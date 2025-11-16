SRCS	= ft_malloc.c ft_malloc_test.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_malloc_test

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LFLAGS	=

RM		= rm -f

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${OBJS} -o ${NAME} ${LFLAGS} 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
