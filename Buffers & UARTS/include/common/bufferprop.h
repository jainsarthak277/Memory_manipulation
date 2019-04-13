/***********************************************************************************
* @bufferprop.h
* @This file contains dependent include files and variable declaration for bufferprop.c
*
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//#define platform_kds
//#define interrupting

#ifdef platform_kds
#include "board.h"
#include "fsl_lptmr_driver.h"
#include "MKL25Z4.h"
#endif

typedef struct
{
	int8_t *buffs;
	__uint16_t front;
	__uint16_t back;
	__uint16_t size;
	__uint16_t count;
} __attribute__((packed))ring_wbells;

ring_wbells* buffinit(__uint16_t length);

int8_t buffinsert(ring_wbells *ring1, int8_t data);

int8_t buffread(ring_wbells *ring1, int8_t *data);

ring_wbells* buffresize(ring_wbells *ring1, __uint16_t length);

