# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 18:27:46 by jkosiara          #+#    #+#              #
#    Updated: 2021/09/09 17:20:48 by jkosiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

CC	     = gcc $(FLAGS)

FLAGS    = -Wall -Werror -Wextra

SERVER_BONUS_SRC = bonus/server_bonus.c  bonus/utils_bonus.c bonus/utils2_bonus.c

CLIENT_BONUS_SRC = bonus/client_bonus.c  bonus/utils_bonus.c bonus/utils2_bonus.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

bonus:	fclean $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
		@$(CC) $(SERVER_BONUS_SRC) -I minitalk_bonus.h -o server_bonus
		@$(CC) $(CLIENT_BONUS_SRC) -I minitalk_bonus.h -o client_bonus

clean :
	@rm -rf ./bonus/*.o $(CLIENT_BONUS) $(SERVER_BONUS) 

fclean: clean
	@rm -rf $(CLIENT_BONUS) $(SERVER_BONUS) 

re: fclean all

.PHONY : bonus all clean fclean
