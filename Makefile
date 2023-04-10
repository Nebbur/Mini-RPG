NAME = rpg

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

CFLAGS = -I.

CC = gcc

RM = rm -f

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re