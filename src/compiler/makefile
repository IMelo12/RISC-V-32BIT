
CC = gcc
CFLAGS = -g -Wall -MMD
OBJECTS = main.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = main


${EXEC} : ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${EXEC}

clean:
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS}

-include ${DEPENDS}

