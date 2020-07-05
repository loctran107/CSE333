CC = gcc
CFLAGS = -Wall -g -std=c11
HEADERs = complex.h

all: complex

complex: test_complex.o complex.o
	$(CC) $(CFLAGS) -o complex test_complex.o complex.o

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean: FORCE
	rm *.o
	
FORCE:
