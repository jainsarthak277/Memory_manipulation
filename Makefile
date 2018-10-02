objects = main.o help.o allocate.o free.o write.o prng.o writepattern.o display.o
headers = main.h help.h allocate.h free.h write.h prng.h writepattern.h display.h

memfun : $(objects) $(headers)
	gcc -o memfun $(objects)

main.o : main.c
	gcc -c main.c

clean : 	
	rm memfun $(objects)

