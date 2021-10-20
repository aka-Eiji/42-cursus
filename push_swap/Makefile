NAME = push_swap
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror
AR = @ar -rcs
RM = @rm -rf
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$ @echo [compiling libft]
	$ @echo [compiling push_swap]
	@make -C libft
	@gcc $(OBJS) libft/libft.a -o $(NAME) -lreadline
	$ @echo [DONE, $(NAME) IS READY!]


%.o: %.c
	@gcc -c -g -I./libft $(CFLAGS) $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all
