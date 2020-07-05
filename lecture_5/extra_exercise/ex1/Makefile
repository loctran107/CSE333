CC = gcc
CFLAGS = -Wall -g -std=c11
HEADERS = ll.h
all: ex1

ex1: ex1.o ll.o
	$(CC) $(CFLAGS) -o ex1 ex1.o ll.o

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<


	


