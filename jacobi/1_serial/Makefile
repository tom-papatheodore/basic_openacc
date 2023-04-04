COMP  = nvc++
FLAGS =

main: main.o
	${COMP} ${FLAGS} main.o -o main

main.o: main.c
	${COMP} ${FLAGS} -c main.c

.PHONY: clean

clean:
	rm -rf main *.o
