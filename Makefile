CC=gcc
CCFLAGS=-Wall -Wextra -ansi -pedantic

all: gettemp
debug: CCFLAGS+= -DDEBUG -g
debug: gettemp
release: CCFLAGS+= -O2
release: gettemp
gettemp: gettemp.o
	$(CC) $(CCFLAGS) -o gettemp gettemp.c
clean:
	rm -rvf gettemp *.o
