/***********************************************************************************
* @uart.h
* @This file contains dependent include files and variable declaration for uart.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "bufferprop.h"

#define BAUD_RATE 115200
//#define BAUD_RATE 9600
#define OSR_VAL 0x0F
#define SIM_SOPT2_FLLCLK 4000000U


void uart_init();
void uart_putc(uint8_t);
void print_string(char* to_print);
void print_int(uint16_t to_print_int);
uint8_t uart_getc(void);

#ifndef interrupting
	uint16_t get_num(void);
#else
	ring_wbells *ring_tx;
	ring_wbells *ring_rx;
	char num_arr[10];
	uint8_t num_count;
	volatile int8_t tx_flag, rx_flag, num_ready, getnum_flag;
	uint16_t get_num(uint8_t c);
#endif



