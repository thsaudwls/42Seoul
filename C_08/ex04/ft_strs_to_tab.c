/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 09:22:46 by myson             #+#    #+#             */
/*   Updated: 2022/01/26 13:13:38 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (src[i] != 0x00)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == 0x00)
		return (0x00);
	while (j < i)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = 0x00;
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
		i++;
	return (i);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == 0x00)
		return (0x00);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].size = 0;
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
