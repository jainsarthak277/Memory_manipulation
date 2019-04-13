/***********************************************************************************
* @main.c
* @This file contains serial interface code for both blocking and non blocking
* implementaion and toggling LEDs and counting Fibonacci series.
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "../include/common/main.h"


#ifdef platform_kds

void lptmr_call_back(void)
{
    // Toggle LEDs
    LED3_TOGGLE;
    LED2_TOGGLE;
    LED1_TOGGLE;
}

void main()
{
    //UART initialization 
    uart_init();

    // LPTMR configurations
    lptmr_user_config_t lptmrConfig =
    {
        .timerMode = kLptmrTimerModeTimeCounter,
        .freeRunningEnable = false,
        .prescalerEnable = true,
        .prescalerClockSource = kClockLptmrSrcLpoClk,
        .prescalerValue = kLptmrPrescalerDivide2,
        .isInterruptEnabled = true,
    };
    // LPTMR driver state information
    lptmr_state_t lptmrState;

    // Initialize standard SDK demo application pins
    hardware_init();

    // Initialize LPTMR
    LPTMR_DRV_Init(LPTMR0_IDX, &lptmrState, &lptmrConfig);
    // Set timer period for TMR_PERIOD seconds
    LPTMR_DRV_SetTimerPeriodUs(LPTMR0_IDX, TMR_PERIOD);
    // Install interrupt call back function for LPTMR
    LPTMR_DRV_InstallCallback(LPTMR0_IDX, lptmr_call_back);
    // Start LPTMR
    LPTMR_DRV_Start(LPTMR0_IDX);

    // Initialize LED1
    LED3_EN;
    LED2_EN;
    LED1_EN;

#ifndef interrupting				//Blocking Code
	print_string("Hey there!!!\n\r");
	while(1)
	{
		print_string("Enter transmit buffer size:\t");		//Get Tx and Rx buffer size till buffer is initialized
		len = get_num();
		ring_tx = buffinit(len);
		if(ring_tx == NULL)
		{
			print_string("Initialization failed\n\r");
		}
		else
		{
			print_string("Buffer initialized\n\r");
			print_string("Enter receive buffer size:\t");
			len = get_num();
			ring_rx = buffinit(len);
			if(ring_rx == NULL)
			{
				print_string("Initialization failed\n\r");
			}
			else
			{
				print_string("Buffer initialized\n\r");
				break;
			}
		}
	}
	while(1)
	{
		ip = uart_getc();		//get character
		uart_putc(ip);			//echo character
		print_string("\n\r");
		switch(ip)
		{
			case '~':		//buffer resize command character
				resize();
				break;
			default:
				break;
		}
		edit_report(ip);		//upadte and print report
	}

#else					//Non-blocking Code
	tx_flag = 1;
	ring_tx = buffinit(500);	//Default buffer initialization
	ring_rx = buffinit(500);
	fibo1 = 0;
	fibo2 = 1;
	fibo_cnt = 1;
	print_string("Hey there!!!\n\r");
	while(1)
	{
		if(tx_flag == 1 && ring_tx -> count != 0)	//Send a byte of data if TX FIFO is not empty and UART is ready to accept
		{
			tx_flag = 0;
			buffread(ring_tx, (int8_t *)&tx_char);
			UART0 -> D = tx_char;
			UART0_C2 |= UART0_C2_TIE_MASK;
		}

		if(ring_rx -> count != 0 && (ring_tx -> count < ring_tx -> size -35))			//Process a received byte if Rx FIFO is not empty and Tx FIFO has atleast 35 bytes of space  
		{											//remaining, this ensure space for report and ensures Tx buffer doesn't overflow
			buffread(ring_rx, (int8_t *)&rx_char);
			uart_putc(rx_char);
			if(getnum_flag == 0)					
			{
				uart_putc('\n');
				uart_putc('\r');
				switch(rx_char)
				{
					case '~': init1 = 1;			//resize buffer
							  break;
					case '!': print_rep++;			//Stop fibonacci series printing, used during file transfer
							  break;
					default:  break;
				}
			}
			else						//non-blocking scanf to get integer input from user
			{
				result = get_num(rx_char);
			}
			edit_report(rx_char);				//update report and add is to Tx fifo
		}

		// Resize lenghth scanf logic
		if(init1 == 1)						
		{
			print_string("Enter resized transmit buffer size:\t");
			getnum_flag = 1;
			init1 = 0;
			init2 = 1;
		}
		if(init2 == 1 && num_ready == 1)
		{
			num_ready=0;
			len = result;
			ring_tx = buffresize(ring_tx, len);
			if(ring_tx == NULL)
			{
				print_string("\n\rResize failed\n\r");
				init1 = 0;
				init2 = 0;
			}
			else
			{
				print_string("Buffer resized\n\r");
				print_string("Enter resized receive buffer size:\t");
				getnum_flag = 1;
				init2 = 0;
				init3 = 1;
			}
		}
		if(init3 == 1 && num_ready == 1)
		{
			num_ready=0;
			len = result;
			ring_rx = buffresize(ring_rx, len);
			if(ring_rx == NULL)
			{
				print_string("\n\rResize failed\n\r");
				init1 = 0;
				init2 = 0;
				init3 = 0;
			}
			else
			{
				print_string("Buffer resized\n\r");
				init3 = 0;
			}
		}

		fibo();				//fibonacci series calculator
	}
#endif
}

#ifndef interrupting	//Resize for non-blocking as scanf is blocking
void resize(void)
{
	while(1)
	{
		print_string("Enter resized transmit buffer size:\t");
		len = get_num();
		ring_tx = buffresize(ring_tx, len);
		if(ring_tx == NULL)
		{
			print_string("Resize failed\n\r");
		}
		else
		{
			print_string("Buffer resized\n\r");
			print_string("Enter resized receive buffer size:\t");
			len = get_num();
			ring_rx = buffresize(ring_rx, len);
			if(ring_rx == NULL)
			{
				print_string("Resize failed\n\r");
			}
			else
			{
				print_string("Buffer resized\n\r");
				break;
			}
		}
	}
}
#endif

#endif

