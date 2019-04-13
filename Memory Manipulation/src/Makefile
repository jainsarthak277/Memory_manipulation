objects = main.o help.o allocate.o free.o write.o prng.o writepattern.o display.o verify.o invert.o
headers = ../inc/main.h ../inc/help.h ../inc/allocate.h ../inc/free.h ../inc/write.h ../inc/prng.h ../inc/writepattern.h ../inc/display.h ../inc/verify.h ../inc/invert.h

memfun : $(objects) $(headers)
	gcc -o memfun $(objects)

main.o : main.c $(headers)
	gcc -c main.c

help.o : help.c ../inc/help.h
	gcc -c help.c

allocate.o : allocate.c ../inc/allocate.h help.o
	gcc -c allocate.c

free.o : free.c ../inc/free.h allocate.o
	gcc -c free.c

write.o : write.c ../inc/write.h allocate.o
	gcc -c write.c

prng.o : prng.c ../inc/prng.h
	gcc -c prng.c

writepattern.o : writepattern.c ../inc/writepattern.h allocate.o
	gcc -c writepattern.c

display.o : display.c ../inc/display.h allocate.o 
	gcc -c display.c

verify.o : verify.c ../inc/verify.h allocate.o prng.o
	gcc -c verify.c

invert.o : invert.c ../inc/invert.h allocate.o
	gcc -c invert.c

test : memfun test.txt
	./memfun < test.txt

clean : 	
	rm memfun $(objects)

