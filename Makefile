SRCS	= utils/ft_atoi.c utils/ft_lstadd_back.c utils/ft_lstadd_front.c utils/ft_lstclear.c utils/ft_lstdelone.c utils/ft_lstiter.c utils/ft_lstlast.c utils/ft_lstmap.c utils/ft_lstnew.c utils/ft_lstsize.c utils/ft_split.c utils/ft_strchr.c utils/ft_strlen.c utils/ft_substr.c instructor.c instructor2.c parseur.c


OBJS	= ${SRCS:.c=.o}


CC	= gcc

RM	= rm -f

CFLAGS    = 

NAME    = push_swap.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}:    ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all


.PHONY:	clean fclean all re