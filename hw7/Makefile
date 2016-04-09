TARGET=band
OBJS=rem.o u2.o ccr.o kiss.o
CFLAGS=-g -Wall

.PHONY: all clean

all: ${TARGET}
${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}
clean:
	rm -f ${TARGET} ${OBJS}
