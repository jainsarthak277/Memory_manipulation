#include "help.h"

void help_fn(char *option, char* dummy1, char *dummy2)
{
	if(dummy1 == NULL && dummy2==NULL)
	{
		if(option == NULL)
		{	
			printf("These are Memory Fun commands:\n\n");
 			printf("%s",allocate_h);
 			printf("%s",free_h);
 			printf("%s",display_h);
 			printf("%s",write_h);
 			printf("%s",invert_h);
			printf("%s",pattern_h);
			printf("%s",verify_h);
 			printf("Press help -command for help on particular command...\n");
		}
		else if(strcmp(option,"allocate")==0)
		{
			printf("allocate\tAllocates a block of memory on input: allocate - size <size>\nThe function allocates 'size' number of 32-bit words to be used further at a location in memory.\n");
		}
		else if(strcmp(option,"free")==0)
		{
			printf("free\t\tReleases previously allocated block on input: free\nThis function frees the memory, making it available for reuse.\n");
		}
		else if(strcmp(option,"display")==0)
		{
			printf("display\t\tDisplay contents of memory on input: display\nThis function displays the memory allocated for use and the value currently stored at those memory locations.\n");
		}
		else if(strcmp(option,"write")==0)
		{
			printf("write\t\tWrite at indicated memory location on input: write - addr <address> - val <value>\nThis function writes the user inputted value at specified memory location. Can be confirmed by displaying.\n");
		}
		else if(strcmp(option,"invert")==0)
		{
			printf("invert\t\tInvert all memory bits on input: invert - addr <address> - size <size>\nThis function inverts all the bits present at a specified memory location, upto the size mentioned.\n");
		}
		else if(strcmp(option,"pattern")==0)
		{
			printf("pattern\t\tWrite pseudo-random pattern to address as: pattern - addr <address> - size <size> - seed <seed value>\nThis function takes the address, size of 32-bit words and seed value from user. It uses these to write a pseudo-random pattern generated from the seed to the memory location inputted, upto the size mentioned.\n");
		}
		else if(strcmp(option,"verify")==0)
		{
			printf("verify\t\tVerify pseudo-random pattern at specified address as: verify - addr <address> - size <size> - seed <seed value>\nThis function takes the address, size of 32-bit words and seed value from user.\nIt uses these to verify if the arguments inputted by user match those inputted in the 'pattern' function. It returns either a 'Verification passed !!!' message upon verification, or a 'Discrepancy found' message along with the actual and expected values.\n");
		}
		else
		{
			printf("Invalid option for help !!!\n");
		}
	}
	else
	{
		printf("More then one option not allowed for this command !!!\n");
	}	
 }
