TARGET=zombie
OBJS=zombie.o
CFLAGS=-g -Wall
LIBS=-lm

.PHONY: all clean

all: ${TARGET}
${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}
clean:
	rm -f ${TARGET} ${OBJS}

