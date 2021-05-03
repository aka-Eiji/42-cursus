NAME = cub3d

LIBFT_DIR = libft/

LIBFT = libft.a

MAP = $(INCLUDE)/maps/maps.cub

SRC = maps/parsingmap.c \

INCLUDE = include

OBJS = $(FILE:.c=.o)

MLX = libmlx.dylib

CC = gcc

HEADER = cub3d.h

FLAGS = -Wall -Wextra -Werror

MLX_F = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3d.h

FILE = $(addprefix include/, $(SRC))

BIN_O = $(addsuffix .o, $(SRC))

$(NAME): $(OBJS)
	@echo "\033[93;1;4mCompiling files ...\033[0m"
	@$(MAKE) -C ./libft
	@$(MAKE) -C mlx
	@mv mlx/libmlx.dylib .
	@mv libft/libft.a .
	@$(CC) $(FLAGS) -o $(NAME) $(MLX) $(MLX_F) $(OBJS) libft.a
	@echo "..."
	@echo "\033[32;1;4mSuccess!\033[0m"

all: $(NAME)

run: $(NAME)
	@make re
	./$(NAME) $(MAP)

clean:
	@echo "\033[31;1;4mDeleting obj files ...\033[0m"
	@rm -rf $(OBJS)
	@$(MAKE) clean -C libft/
	@echo "..."
	@echo "\033[32;1;4mDone!\033[0m"

fclean:
	@echo "\033[31;1;4mDeleting exe ...\033[0m"
	@rm -f $(NAME) $(MLX) libft.a
	@echo "..."
	@echo "\033[32;1;4mAll good!\033[0m"


re: fclean all
