# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 18:27:46 by jkosiara          #+#    #+#              #
#    Updated: 2021/06/09 18:27:49 by jkosiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server

CLIENT   = client

CC	     = gcc

#FLAGS    = -Wall -Werror -Wextra

SERVER_SRC = server.c utils.c utils2.c 

CLIENT_SRC = client.c error.c 

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o utils.o utils2.o minitalk.h
	@$(CC) server.o utils.o utils2.o -o $@ 

$(CLIENT) : client.o error.o utils.c utils2.c minitalk.h
	@$(CC) client.o error.o utils.c utils2.c -o $@

%.o : %.c
	@$(CC) -c $(SERVER_SRC) $(CLIENT_SRC) -c -I minitalk.h

clean :
	@rm -rf *.o

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all