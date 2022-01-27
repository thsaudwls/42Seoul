/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:51:51 by myson             #+#    #+#             */
/*   Updated: 2022/01/24 14:21:40 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
		i ++;
	return (i);
}

int	ft_len2(char **strs, int size)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while ((*strs)[j] != 0x00)
		{
			j ++;
			len ++;
		}
		i ++;
		strs ++;
	}
	return (len);
}

char	*sub(int size, char **strs, char *tmp, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tmp;
	int		sep_len;
	int		len;

	sep_len = ft_len1(sep);
	len = ft_len2(strs, size);
	if (size == 0)
	{
		tmp = (char *)malloc(sizeof(char) * 1);
		tmp[0] = 0x00;
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(char) * (len + (size - 1) * sep_len + 2));
	if (tmp == 0x00)
		return (0);
	tmp = sub(size, strs, tmp, sep);
	return (tmp);
}

char	*sub(int size, char **strs, char *tmp, char *sep)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (size-- > 0)
	{
		i = 0;
		while ((*strs)[i] != 0x00)
			tmp[m++] = (*strs)[i++];
		strs ++;
		i = 0;
		if (size != 0)
			while (sep[i] != 0x00)
				tmp[m++] = sep[i++];
	}
	tmp[m] = 0x00;
	return (tmp);
}
