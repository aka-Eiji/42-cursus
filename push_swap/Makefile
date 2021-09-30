NAME = 	push_swap
HEADER = push_swap.h 
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=o)

all:
	$(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(OBJS) libft/libft.a -o $(NAME) -lreadline

	%.o: %.c
	gcc -c -g -I./libft $(CFLAGS) $< -o $@

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all
