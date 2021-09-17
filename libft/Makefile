NAME	= libft.a

SRCS	= $(shell find . -name "ft_*.c")

RM		= rm -f

OBJS	= ${SRCS:.c=.o}

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

.c.o.:
	$(CC) ${FLAGS} - I includes -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all:	${NAME}

clean: 
	 ${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all, clean, fclean, re
