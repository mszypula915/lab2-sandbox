all: mastermind

CC = gcc
CFLAGS = -g -Wall
OBJS = main.o mastermind.o

mastermind: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) mastermind 
