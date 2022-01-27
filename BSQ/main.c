/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejhong <yejhong@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:52:29 by yejhong           #+#    #+#             */
/*   Updated: 2022/01/27 12:15:33 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include <stdio.h>

int		**ft_fill_square(int **map, int *max_index);
char	**set(char *buf);
int		*dis_array(char *buf, int *xy);
int		check_valid(char *buf_malloc);

char	*sub_main_1(int argc, char *buf_malloc, char *buf)
{
	int		i;
	char	c;
	int		cnt2;

	cnt2 = 0;
	i = 0;
	if (argc == 1)
	{
		i = 0;
		while (read(1, &c, 1) > 0)
		{
			buf[cnt2] = c;
			cnt2 ++;
			if (buf[cnt2] == '\n' && buf[cnt2 - 1] == '\n')
				break ;
		}
		buf[cnt2] = 0x00;
		buf_malloc = (char *) malloc (sizeof(char) * cnt2 + 1);
		buf_malloc = ft_strcpy(buf_malloc, buf);
		if (check_valid(buf_malloc) == 0)
			return (0);
	}
	return (buf_malloc);
}

void	print(int *xy, char **map_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < xy[1])
	{
		j = 0;
		while (j < xy[0])
		{
			write(1, &map_array[i][j], 1);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
	write(1, "\n", 1);
}

int	sub_main_2(char **argv, char *buf, int cnt)
{
	int		*xy;
	int		fd;
	int		length;
	char	**map_array;

	xy = (int *)malloc(sizeof(int) * 3);
	fd = open(argv[cnt], O_RDONLY);
	if (fd == -1)
		exit(1);
	length = read(fd, buf, BUF_SIZE);
	buf[length] = 0x00;
	map_array = set(buf);
	xy = dis_array(buf, xy);
	print(xy, map_array);
	close(fd);
	cnt ++;
	return (cnt);
}

int	main(int argc, char **argv)
{
	char	buf[BUF_SIZE];
	char	*buf_malloc;
	int		cnt;

	cnt = 1;
	buf_malloc = sub_main_1(argc, buf_malloc, buf);
	if (argc == 1)
		argc = 2;
	while (cnt < argc || argc != 1)
		cnt = sub_main_2(argv, buf, cnt);
}
