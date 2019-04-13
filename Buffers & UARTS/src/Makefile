TARGET = unit
SOURCES = bufferprop.c \
	unittest.c
SOURCES_KL25Z = bufferprop.c \
	main.c \
	report.c \
	uart.c \
	system_MKL25Z4.c
PLATFORM = HOST
CPU = cortex-m0plus
ARCHITECTURE = armv6-m
FPU = fpv4-sp-d16
SPECS = nosys.specs 
PRINTALLOW = KL25Z
LINKER_FILE = ./platform/MKL25Z128xxx4_flash.ld
INCLUDES_KL25Z = -I ./include/common \
		-I ./include/CMSIS \
		-I ./include/kl25z

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS = -g -O0 -std=c99
	CPPFLAGS = -DHOST -DPROJECT1 -D VERBOSE
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJFILES = $(SOURCES:.c=.o)
endif

ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabihf-gcc
	CFLAGS = -g -O0 -std=c99
	CPPFLAGS = -DBBB -DPROJECT1 -D VERBOSE
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJFILES = $(SOURCES:.c=.o)
endif

ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
	CFLAGS = -g -O0 -std=c99 -mcpu=$(CPU) \
		 -mthumb -march=$(ARCHITECTURE) -mfloat-abi=soft \
		 -mfpu=$(FPU) --specs=$(SPECS) $(INCLUDES_KL25Z)
	CPPFLAGS = -DKL25Z -DPROJECT1 -D$(PRINTALLOW)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	OBJFILES = $(SOURCES_KL25Z:.c=.o) 
endif

%.o : %.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

%.asm : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $< -o $@

%.i : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $< -o $@

build : $(OBJFILES)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJFILES) -lcunit -o $(TARGET).elf

clean : 
	rm -f *.o
	rm -f unit.elf
	rm -f *.i
	rm -f *.map
	rm -f *.asm

