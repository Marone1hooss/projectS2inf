#-*-Makefile-*-
SRCS = main.c \
	  sorting.c \

OBJS = ${SRCS:%.c=%.o}

NAME = main

#Linking step:
${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

#Compilation step:

%.o: %.c math.h
	gcc -c $< -o $@

#main:main.o sorting.o
#	gcc main.o sorting.o -o main
#main.o:main.c sorting.h
#	gcc -c main.c
#sorting.o:sorting.c sorting.h
#	gcc -c sorting.c*/

clean:
	rm -f *.o  main