objects = main.o
headers = main.h

memfun : $(objects) $(headers)
	gcc -o memfun $(objects)

main.o : main.c
	gcc -c main.c

clean : 	
	rm memfun $(objects)

