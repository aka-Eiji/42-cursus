NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror
AR = @ar -rcs
RM = @rm -f
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
