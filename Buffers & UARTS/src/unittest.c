/***********************************************************************************
* @unittest.c
* @This file contains randomized testbench code for buffer testing
* 
* @author Vatsal Sheth & Sarthak Jain
************************************************************************************/

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include "CUnit/Automated.h"
#include <time.h>
#include "../include/common/bufferprop.h"

ring_wbells *ring_test;
__uint16_t length;

//generate time based seed
int init_suite1(void)
{
	srand(time(0));
	return 0;
}

//Free buffer while exiting
int clean_suite1(void)
{
	free(ring_test);
	return 0;
}

//Test for random buffer length initialization
void init_buffer(void)
{
	length = (rand() % 65534)+1;
	CU_ASSERT(NULL == buffinit(0));
	ring_test = buffinit(length);
	CU_ASSERT(ring_test != NULL);
	printf("length is %d ",length);
}

//Test for buffer access in entire lenghth and overflow underflow
void test_buffer(void)
{
	__uint16_t i=0;
	__uint8_t data;
	
	for(i=0; i<length; i++)
	{
		data = rand() % 256;
		CU_ASSERT(0 == buffinsert(ring_test, data));
	}
	data = rand() % 256;
	CU_ASSERT(-1 == buffinsert(ring_test, data));
	
	for(i=0; i<length; i++)
	{
		CU_ASSERT(0 == buffread(ring_test, &data));
	}
	CU_ASSERT(-1 == buffread(ring_test, &data));
}

//Test for buffer resize
void test_resize(void)
{
	length = (rand() % 65534)+1;	
	ring_test = buffresize(ring_test,length);
	CU_ASSERT(ring_test != NULL);
	printf("Resized length is %d ",length);
}

//Test for valid data at valid locations
void test_data_buffer(void)
{
	__uint16_t i=0;
	__uint8_t data;
	
	for(i=0; i<length; i++)
	{
		CU_ASSERT(0 == buffinsert(ring_test, i%256));
	}
		
	for(i=0; i<length; i++)
	{
		buffread(ring_test, &data);
		CU_ASSERT((i%256) == data);
	}
}

int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
	if (NULL == pSuite) 
	{
	      CU_cleanup_registry();
	      return CU_get_error();
	}
	
	/* add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "Test for Buffer init", init_buffer)) 
	|| (NULL == CU_add_test(pSuite, "Test for Buffer access", test_buffer)) 
	|| (NULL == CU_add_test(pSuite, "Test for Buffer resize", test_resize))
	|| (NULL == CU_add_test(pSuite, "Test for Buffer data validity", test_data_buffer)))
   	{
      		CU_cleanup_registry();
      		return CU_get_error();
   	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_automated_run_tests();
  	CU_cleanup_registry();
   	return CU_get_error();
}



