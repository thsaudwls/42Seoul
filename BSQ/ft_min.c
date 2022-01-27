/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejhong <yejhong@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:16 by yejhong           #+#    #+#             */
/*   Updated: 2022/01/27 11:35:06 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	map_init(int **map, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		if (map[i][0] != -1)
		{
			map[i][0] = 1;
		}
		i++;
	}
	j = 0;
	while (j < x)
	{
		if (map[0][j] != -1)
			map[0][j] = 1;
		j++;
	}
}

int	ft_three_min_compare(int **map, int i, int j)
{
	int	three_min;

	three_min = 21e8;
	if (map[i - 1][j] == -1 || map[i][j - 1] == -1 || map[i - 1][j - 1] == -1)
		return (0);
	if (map[i - 1][j] < three_min)
		three_min = map[i - 1][j];
	if (map[i][j - 1] < three_min)
		three_min = map[i][j - 1];
	if (map[i - 1][j - 1] < three_min)
		three_min = map[i - 1][j - 1];
	return (three_min);
}

int	*min_calc(int **map, int i, int j, int *three_min, int *max_index)
{
	*three_min = ft_three_min_compare(map, i, j);
	if (map[i][j] == -1)
		map[i][j] = 0;
	else
		map[i][j] = *three_min + 1;
	if (*three_min + 1 > max_index[2])
	{
		max_index[2] = *three_min + 1;
		max_index[0] = i;
		max_index[1] = j;
	}
	else if (*three_min + 1 == max_index[2])
	{
		if (i * i + j * j < max_index[0] * max_index[0] + \
				max_index[1] * max_index[1])
		{
			max_index[0] = i;
			max_index[1] = j;
		}
	}
	return (max_index);
}

int	*ft_max(int **map, int y, int x, int *max_index)
{
	int	i;
	int	j;
	int	three_min;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i - 1 < 0 || j - 1 < 0)
			{
				j++;
				continue ;
			}
			max_index = min_calc(map, i, j, &three_min, max_index);
			j ++;
		}
		i++;
	}
	return (max_index);
}
