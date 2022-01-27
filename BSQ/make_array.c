/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:44:53 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 12:37:27 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

int	*dis_array(char *buf, int *xy)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i ++;
	m = 0;
	i ++;
	while (buf[i + m] != 0x00)
	{
		while (buf[i + m] != '\n' && buf[i + m] != 0x00)
			m ++;
		m++;
		j ++;
	}
	xy[0] = (m - 1) / j;
	xy[1] = j;
	return (xy);
}

int	**sub1(int x, int buffer, char *symbol, int **map, int cnt)
{
	int	total;
	int	j;

	j = 0;
	while (j < x)
	{
		total = x * i + j + buffer + cnt;
		if (buf[total] == symbol[0])
			map[i][j] = 0;
		else
		{
			map[i][j] = -1;
		}
		j ++;
	}
	return (map);
}

int	**ft_make_map(int x, int y, char *buf, char *symbol)
{
	int	**map;
	int	i;
	int	buffer;
	int	cnt;

	i = 0;
	buffer = 0;
	cnt = 0;
	while (buf[buffer] != '\n')
		buffer ++;
	buffer ++;
	map = (int **) malloc (sizeof(int *) * y);
	while (i < y)
	{
		map[i] = (int *) malloc (sizeof(int) * x);
		map = sub(x, buffer, symbol, map, cnt);
		i ++;
		cnt ++;
	}
	return (map);
}

int	**ft_fill_square(int **map, int *max_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_index[2])
	{
		j = 0;
		while (j < max_index[2])
		{
			map[max_index[0] - i][max_index[1] - j] = -2;
			j ++;
		}
		i ++;
	}
	return (map);
}
