/***********************************************************************************
* @main.h
* @This file contains dependent include files and variable declaration for main.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "report.h"
#include <math.h>

void edit_report(uint8_t c);
void resize(void);

// LED Timer period: .25S
#define TMR_PERIOD         250000U

int8_t bufferindata;
uint16_t result;
uint16_t len, resiz;
int8_t bufferoutdata;
uint8_t ip;

#ifdef interrupting
uint8_t tx_char, rx_char;
#endif
