/***********************************************************************************
* @uart.c
* @This file contains uart driver code and print and scan APIs
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/


#include "../include/common/uart.h"

//Uart initialization 
void uart_init()
{
	/*Clock Enable*/
		SIM->SCGC4 |= SIM_SCGC4_UART0_MASK; //turn ON clock gate
		//SIM->SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
		SIM->SOPT2 |= 0x4000000; //FLL or PLL Clock

		UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);

		UART0->C1 &= ~(UART0_C1_M_MASK | UART0_C1_PE_MASK);
		UART0->BDH &= ~UART_BDH_SBNS(1);

		/*Baud Config*/
		uint16_t SBR=((SystemCoreClock)/(OSR_VAL*BAUD_RATE));
		UART0_C4=UART0_C4_OSR(0x0F);
		UART0_BDH= /*0x00;*/((SBR>>8)& UART0_BDH_SBR_MASK);
		UART0_BDL= /*146;*/(SBR & UART0_BDL_SBR_MASK);
		SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK; //enable PORTA
		PORTA_PCR1 = PORT_PCR_MUX(2);
		PORTA_PCR2 = PORT_PCR_MUX(2);

		/*Enable Transmitter, Receiver and Receiver interrupt*/
		UART0_C2 |= (UART0_C2_TE_MASK)|(UART_C2_RE_MASK); //transmitter enable, Receiver enable

		UART0_S1 &= ~(UART0_S1_TDRE_MASK | UART0_S1_RDRF_MASK | UART0_S1_TC_MASK);

#ifdef interrupting
		UART0_C2 |= UART0_C2_TIE_MASK | UART0_C2_RIE_MASK;
		/*Enable IRQ*/
		__enable_irq();

		NVIC_EnableIRQ(UART0_IRQn);
#endif
}


//Uart write a byte of data
void uart_putc(uint8_t data)
{
#ifndef interrupting
	while(!(UART0 -> S1 & UART_S1_TDRE_MASK)); //Waiting for the buffer to get empty
	UART0->D = data;
#else
	buffinsert(ring_tx, (int8_t)data);
#endif
}

//Uart get a byte of data
uint8_t uart_getc()
{
	int8_t data;
	data = 0;
#ifndef interrupting
	while((UART0 -> S1 & UART_S1_RDRF_MASK) == 0);
	data = UART0->D;
	return data;
#else
	int8_t valid;
	valid = buffread(ring_rx, &data);
	if(valid == -1)
	{
		return 0;
	}
	return data;
#endif
}

#ifdef interrupting
void UART0_IRQHandler(void)
{
	__disable_irq();	//Disable all interrupts
	if((UART0_S1 & UART0_S1_TDRE_MASK))
		{
			tx_flag = 1;
			UART0_C2 &= ~UART0_C2_TIE_MASK;
		}

	if((UART0_S1 & UART0_S1_RDRF_MASK))
	{
		rx_flag = 1;
		buffinsert(ring_rx, UART0 -> D);
	}

	__enable_irq();		//Enable all interrupts
	return;
}
#endif

//Send string of data
void print_string(char* to_print)
{
	while(*to_print != '\0')
	{
		uart_putc(*(to_print++));
	}
}


//Send integer as consequtive characters
void print_int(uint16_t to_print_int)
{
	uint8_t i = 5, valid = 0;
	uint32_t div = 10000;
	while(i != 0)
	{
		if(to_print_int/div || valid == 1 || i==1)
		{
			valid = 1;
			uart_putc(0x30 + to_print_int/div);
		}
		to_print_int = to_print_int % div;
		div = div/10;
		i--;
	}
}

//Scan interger from user
#ifndef interrupting	//non-blocking
uint16_t get_num()
{
    char str[10];
    uint8_t i=0;
    while(1)
    {
        str[i] = uart_getc();
        if(str[i]=='\r')            //Enter logic
        {
            str[i] = '\0';
            uart_putc('\n');
            uart_putc('\r');
            break;
        }
        else if(str[i]==0x7f)           //Backspace logic
        {
        	uart_putc(str[i]);
            i-=1;
        }
        else if(str[i]>='0' && str[i]<='9')         //Decimal check
        {
        	uart_putc(str[i]);
            i+=1;
        }
        else
        {
        	uart_putc(str[i]);
            print_string("\n\rNot a decimal !!! Enter Again\n\r");
            i=0;
        }

    }
    return atoi(str);
}
#else		//blocking
uint16_t get_num(uint8_t c)
{
	num_arr[num_count] = c;
	if(num_arr[num_count] == '\r')
	{
		uart_putc('\n');
    	num_arr[num_count] = '\0';
    	getnum_flag = 0;
    	num_count = 0;
    	num_ready = 1;
    }
    else if((num_arr[num_count]>='0' && num_arr[num_count]<='9'))
    {
    	num_count ++;
    }
    else
    {
    	print_string("\n\rNot a decimal !!! Enter Again\n\r");
    	num_count = 0;
    }
    return atoi(num_arr);
}
#endif
