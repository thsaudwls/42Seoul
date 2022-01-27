/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejhong <yejhong@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:04:39 by yejhong           #+#    #+#             */
/*   Updated: 2022/01/27 10:56:32 by yejhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int	ft_check_condition(char *line, int len)
{
	int		idx;
	int		value;
	char	*size;

	if (len < 3)
		return (0);
	idx = 0;
	while (idx < len - 3)
	{
		if (!(line[idx] >= '0' && line[idx] <= '9'))
			return (0);
		idx++;
	}
	size = (char *)malloc(sizeof(char) * (len - 3));
	if (!size)
		return (0);
	ft_strncpy(size, line, len - 3);
	value = ft_atoi(size);
	free(size);
	return (value);
}

int	ft_symbol_check(char ch, char *buf_malloc, int m)
{
	while (*buf_malloc)
	{
		if (ch == *(buf_malloc++))
			return (0);
	}
	return (1);
}
/*
int	ft_put_symbols(t_map *meta_map, char *line, int len)
{
	int		idx;
	char	ch;

	meta_map->symbol[0] = line[len - 1]; // 채울 거 (x.)
	meta_map->symbol[1] = line[len - 2]; // 장애물 (o)
	meta_map->symbol[2] = line[len - 3];// 빈 곳(.)
	idx = 0;
	while (idx < 3)
	{
		ch = meta_map->symbol[idx++];
		if (ft_symbol_check(ch, meta_map->symbol)) //1리턴 받으면 리턴0
			return (0);
	}
	return (1);
}*/
