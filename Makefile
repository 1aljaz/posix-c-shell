CC = gcc
CFLAGS = -Wall

all:
	$(CC) $(CFLAGS) shell.c parser.c execute.c -o shell

clean:
	rm -f shell *.o