NAME	=	so_long

SRCS	= 	all/*.c so_long.c so_long_utils.c so_long_parse_map.c so_long_parse_map2.c so_long_parse_2.c ft_game_utils.c ft_flood_fill.c ft_game.c

OBJCT	=	${all:.c=.o}

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror -I./mlx

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC)  $(SRCS)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	# $(CC)  $(SRCS)  -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all