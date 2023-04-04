#----------------------------------------
CC    = nvc++
FLAGS = -acc -Minfo=accel
#----------------------------------------

vector_addition: vector_addition.o
	${CC} ${FLAGS} vector_addition.o -o vector_addition

vector_addition.o: vector_addition.c
	${CC} ${FLAGS} -c vector_addition.c

.PHONY: clean

clean:
	rm -f vector_addition *.o
