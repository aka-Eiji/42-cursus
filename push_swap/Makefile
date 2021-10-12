NAME = 	push_swap
HEADER = push_swap.h 
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf
SRC = src/operations.c src/moves_a.c src/moves_b.c src/parsing.c src/push_swap.c src/utils.c src/utils_2.c \

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -o $(NAME) $(CFLAGS) $(SRC) libft/libft.a -I $(HEADER)

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all
