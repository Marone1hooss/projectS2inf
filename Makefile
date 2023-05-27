#-*-Makefile-*-
SRCS = main.c \
	  sorting.c \
	  AVL.c \

OBJS = ${SRCS:%.c=%.o}

NAME = main

#Linking step:
${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

#Compilation step:

%.o: %.c sorting.h AVL.h
	gcc -Wall -Wextra -g -c $< -o $@

run: 
	main 

clean:
	rm -f *.o  main