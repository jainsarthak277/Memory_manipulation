objects = main.o help.o allocate.o
headers = main.h help.h allocate.h

memfun : $(objects) $(headers)
	gcc -o memfun $(objects)

main.o : main.c
	gcc -c main.c

clean : 	
	rm memfun $(objects)

