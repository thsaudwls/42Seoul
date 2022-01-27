# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 14:11:27 by myson             #+#    #+#              #
#    Updated: 2022/01/26 16:18:19 by myson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
TARGET = libft.a
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TARGET) : $(OBJS)
	ar rcs $(TARGET) $(OBJS)

.PHONY: all clean fclean re

all : $(TARGET)

clean:
	${RM} $(OBJS)

fclean: clean 
	${RM} $(TARGET)

re: fclean all
