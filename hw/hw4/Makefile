CC = gcc
CFLAGS = -Wall -g -std=c11 -c
HEADERS = NthPrime.h

all: ex4
	

ex4: ex4.o NthPrime.o
	$(CC) $(CFLAGS) -o ex4 ex4.o NthPrime.o

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $<


