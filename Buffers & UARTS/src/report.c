/***********************************************************************************
* @report.c
* @This file contains report update and fibonacci counter codes
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "../include/common/report.h"

//update and print report
void edit_report(uint8_t c)
{
	uint8_t i=0;
	char_count[c]++;
#ifdef interrupting
	if(!(init1 || init2 || init3))
#endif
	{
#ifdef interrupting
		if(print_rep%2 == 0)
		{
			print_string("Fibonacci no. ");
			print_int(fibo_cnt);
			print_string(": \t");
			print_int(fibo1);
			print_string("\n\r");
		}
#endif
		for(i=32; i<127; i++)
		{
			if(char_count[i]>0)
			{
				uart_putc(i);
				print_string("\t");
				print_int(char_count[i]);
				print_string("\n\r");
			}
		}
	}
}

//fibonacci counter
void fibo(void)
{
	if(fibo_cnt%25 == 0)
	{
		fibo1 = 0;
		fibo2 = 1;
		fibo_cnt = 1;
	}
	fibo_tmp = fibo2;
	fibo2 = fibo2 + fibo1;
	fibo1 = fibo_tmp;
	fibo_cnt ++;
}
