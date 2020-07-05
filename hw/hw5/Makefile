CC = gcc
CFLAGS = -Wall -g -std=c11
HEADERS = Vector.h

all: vector

vector: ex5.o Vector.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm *.o *.a *~ vector

