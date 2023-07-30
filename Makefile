NAME	=	so_long

SRCS	= 	all/*.c so_long.c so_long_parsing.c lst.c so_long_parse_map.c

OBJCT	=	${all:.c=.o}

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC)  $(SRCS) -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all