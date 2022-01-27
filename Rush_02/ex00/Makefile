# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 21:18:19 by dongjlee          #+#    #+#              #
#    Updated: 2022/01/23 21:18:20 by dongjlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I includes
TARGET = rush-02
RM = rm -rf

$(TARGET) : rush02.o main.o check_valid.o check_matching.o func_one.o func_get_size.o func_get_file.o func_ft_all.o func_find_str.o
	$(CC) $(CFLAGS) -o $(TARGET) rush02.o main.o check_valid.o check_matching.o func_one.o func_get_size.o func_get_file.o func_ft_all.o func_find_str.o

rush02.o : rush02.c
	$(CC) $(CFLAGS) -c rush02.c
	
main.o : main.c
	$(CC) $(CFLAGS) -c main.c
	
check_valid.o : check_valid.c
	$(CC) $(CFLAGS) -c check_valid.c

check_matching.o : check_matching.c
	$(CC) $(CFLAGS) -c check_matching.c

func_one.o : func_one.c
	$(CC) $(CFLAGS) -c func_one.c

func_get_size.o : func_get_size.c
	$(CC) $(CFLAGS) -c func_get_size.c

func_get_file.o : func_get_file.c
	$(CC) $(CFLAGS) -c func_get_file.c

func_ft_all.o : func_ft_all.c
	$(CC) $(CFLAGS) -c func_ft_all.c

func_find_str.o : func_find_str.c
	$(CC) $(CFLAGS) -c func_find_str.c

all : $(TARGET)

clean :
	${RM} rush02.o main.o check_valid.o check_matching.o func_one.o func_get_size.o func_get_file.o func_ft_all.o func_find_str.o

fclean : clean
	${RM} rush-02

re : fclean all

.PHONY : rush02.o main.o check_valid.o check_matching.o func_one.o func_get_size.o func_get_file.o func_ft_all.o func_find_str.o all clean fclean re rush-02
