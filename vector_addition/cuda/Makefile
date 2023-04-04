#----------------------------------------
GPUCC    = nvcc
GPUFLAGS =
#----------------------------------------

vector_addition: vector_addition.o
	${GPUCC} ${GPUFLAGS} vector_addition.o -o vector_addition

vector_addition.o: vector_addition.cu
	${GPUCC} ${GPUFLAGS} -c vector_addition.cu

.PHONY: clean

clean:
	rm -f vector_addition *.o
