CC = gcc
CFLAGS = -Wall -g -std=c11
PROGS = server client

all: $(PROGS)

server: tcp_server.c
	$(CC) $(CFLAGS) -o $@ $<

client: tcp_client.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *~ $(PROGS)


