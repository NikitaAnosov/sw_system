CC=gcc
CFLAGS= -Wall -g
all: stringProg
stringProg: main.o
	$(CC) $(CFLAGS) -o stringProg main.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
.PHONY: clean all
clean:
	rm -f *.o stringProg