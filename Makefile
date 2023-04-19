.SILENT:

NAME = rpg

SRCS_AUX = ${wildcard srcs/auxiliary/*.c}
SRCS = ${wildcard srcs/*.c}
OBJS = ${SRCS:.c=.o} ${SRCS_AUX:.c=.o}

CFLAGS = -I.

CC = cc

RM = rm -f

Red=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
RESET=\033[0m

re: fclean all check

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@printf "Static library created.\n"

all: ${NAME} check

clean:
	${RM} ${OBJS}
	@printf "All created objects were removed.\n"

fclean: clean
	${RM} ${NAME}
	@printf "The executable has been removed.\n"

check:
	@if [ -z "$(filter-out $(wildcard $(OBJS)),$(OBJS))" ]; then \
		printf "$(GREEN)Success: All files created successfully.$(RESET)\n"; \
	else \
		printf "$(Red)Error:$(RESET) Some files creation failed.\n"; \
	exit 1; \
	fi

author: 
	@printf "rboia-pe\n"

.PHONY: clean fclean all re check
