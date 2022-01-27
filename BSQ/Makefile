# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejhong <yejhong@student.42seoul.f>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 21:05:47 by yejhong           #+#    #+#              #
#    Updated: 2022/01/26 21:13:10 by yejhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft_atoi.c ./srcs/ft_min.c ./srcs/ft_main.c ./srcs/ft_verify_map.c ./srcs/ft_map_condition.c ./srcs/ft_strdup.c ./srcs/make_array.c ./srcs/ft_str.c

OBJS = ${SRCS:.c=.o}

INCS = includes

NAME = bsq

CC = gcc

RM = rm -f

CFLAGS= -Wall -Wextra -Werror 

.c.o : 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all : ${NAME}

run :
	./${NAME}

clean :
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
