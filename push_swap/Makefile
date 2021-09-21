NAME	=	push_swap

SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

%.o :	%.c
		gcc -c -g $< -o $@

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			gcc $(CFLAGS) $(OBJS) libft.a -o $(NAME)

all:		$(NAME)

clean:		
			rm -f $(OBJS)
			make -C libft clean

fclean:		clean
			rm -f $(NAME_BONUS)
			rm -f $(NAME) libft.a

re:			fclean all

.PHONY:		all clean fclean re
