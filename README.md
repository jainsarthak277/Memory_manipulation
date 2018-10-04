# Memory_manipulation

Makefile is ready with all required headers and objects.
On running target "memfun", the program displays a welcome message, followed by a prompt.

At this point, all commands are ready: help, free, allocate, write, display, invert, write pattern, verify and exit.
Help menu can be called by inputting "help". A list of commands and their functionality will pop up. By typing 'help - <command>', further instructions pop up on how to use that particular command.
The function 'allocate' allocates a block of memory on inputting: allocate - size <size>. It allocates 'size' number of 32-bit words to be used further at a location in memory.

Similarly, the 'help-<command>' is quite extensive, with all commands and their usage mentioned there.

We have tried to implement a Linux style GUI, where the specific 'command - <option> - <option> - <option>' would be the input for a function requiring three arguments. Our logic was to create a structure as a lookup table, having a function pointer with the three arguments as character pointers. For functions requiring less than three inputs, the character pointers are passed as dummy. The program removes all spaces and breaks up the input string basis the '-', passing the string as parameter and the characters in between each '-' as options.
The required function is called based upon the input, with the characters in between each '-' being passed as arguments. Required processing is performed.
We have also added the option for offset, where if a command like write, invert, pattern or verify is used wth the option offset as: 'command - offset<offset size>', memory is automatically allocated as 'memory allocated + offset'. Instead of the user typing out the address everytime, only offset can be typed out, making the interface easier for user as well as for testing.

By inputting "q" or "Q" at the prompt, the program shall exit.
