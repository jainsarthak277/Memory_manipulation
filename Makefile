objects = main.o help.o allocate.o free.o write.o prng.o writepattern.o display.o verify.o invert.o
headers = main.h help.h allocate.h free.h write.h prng.h writepattern.h display.h verify.h invert.h

memfun : $(objects) $(headers)
	gcc -o memfun $(objects)

main.o : main.c main.h
	gcc -c main.c

help.o : help.c help.h
	gcc -c help.c

allocate.o : allocate.c allocate.h
	gcc -c allocate.c

free.o : free.c free.h
	gcc -c free.c

write.o : write.c write.h
	gcc -c write.c

prng.o : prng.c prng.h
	gcc -c prng.c

writepattern.o : writepattern.c writepattern.h
	gcc -c writepattern.c

display.o : display.c display.h
	gcc -c display.c

verify.o : verify.c verify.h
	gcc -c verify.c

invert.o : invert.c invert.h
	gcc -c invert.c

clean : 	
	rm memfun $(objects)

