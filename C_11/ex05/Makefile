# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:57:24 by myson             #+#    #+#              #
#    Updated: 2022/01/27 17:25:32 by myson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_putnbr.c function.c
OBJS = ft_atoi.o ft_putnbr.o function.o
TARGET = do-op
RM = rm -rf

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

all : $(TARGET)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(TARGET)

re: fclean all

.PHONY: all clean fclean re
