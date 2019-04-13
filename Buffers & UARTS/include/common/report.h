/***********************************************************************************
* @report.h
* @This file contains dependent include files and variable declaration for report.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "uart.h"

#ifndef HEADERS_REPORT_H_
#define HEADERS_REPORT_H_

uint8_t char_count[128];
uint8_t print_rep, init1, init2, init3, fibo_cnt;
uint16_t fibo1, fibo2, fibo_tmp;

void edit_report(uint8_t);
void fibo(void);

#endif /* HEADERS_REPORT_H_ */
