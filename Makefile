CC=gcc
CFLAGS=-Wall -g -std=c99
LDFLAGS=-g
TARGET= navy


all: ${TARGET}

run: navy
	./navy-server ./navy-dumb ./navy-dumb

navy: navy.o 
		${CC} ${LDFLAGS} -o $@ $^
%.o: %.c 
		${CC} -c ${CFLAGS} -o $@ $<

clean:
		rm -f *.o
mrproper: clean
		rm -f ${TARGET}
