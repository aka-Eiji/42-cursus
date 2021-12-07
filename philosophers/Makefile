NAME	=	philo

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

LIB		=	-pthread

SRCS	=	srcs/philo.c \
			srcs/utils.c \
			srcs/philo_utils.c \
			srcs/init.c \
			srcs/libft_utils.c \
			srcs/cycle.c \
			srcs/monitoring.c \
			srcs/free.c

HEADER	=	-I /includes

OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${FLAG} ${HEADER} -c $< -o ${<:.c=.o}

all:		philo

philo:		${OBJS}
				${CC} ${FLAG} ${LIB} ${HEADER} ${OBJS} -o ${NAME}

clean:		
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean	all

.PHONY:		all clean fclean re philo