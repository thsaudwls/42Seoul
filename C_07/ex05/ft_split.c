/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:07:19 by myson             #+#    #+#             */
/*   Updated: 2022/01/25 16:16:56 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_split(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0x00)
	{
		if (str == charset[i])
			return (1);
		i ++;
	}
	return (0);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
		i ++;
	return (i);
}

char	**sub(char **arr, char *str, char *charset, int cnt);
int		sub1(int i, char *charset, char *str);

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**arr;
	int		cnt;

	i = 0;
	if (*charset == 0x00)
	{
		arr = (char **) malloc (sizeof(char *) * 2);
		arr[0] = (char *) malloc (sizeof(char) * ft_len(str) + 1);
		while (i < ft_len(str))
		{
			arr[0][i] = str[i];
			i ++;
		}
		arr[1] = 0;
		return (arr);
	}
	i = 0;
	cnt = sub1(i, charset, str);
	arr = (char **) malloc (sizeof(char *) * (cnt + 1));
	if (arr == 0x00)
		return (0x00);
	arr = sub(arr, str, charset, 0);
	arr[cnt] = 0;
	return (arr);
}

int	sub1(int i, char *charset, char *str)
{
	int	cnt;
	int	j;

	cnt = 0;
	j = 0;
	while (str[i] != 0x00)
	{
		j = 0;
		if (check_split(str[i], charset) != 0)
			i ++;
		if (str[i] == 0x00)
			break ;
		while (check_split(str[i], charset) == 0)
		{
			j ++;
			i ++;
		}
		if (j != 0)
			cnt ++;
	}
	return (cnt);
}

char	**sub(char **arr, char *str, char *charset, int cnt)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	while (str[i] != 0x00)
	{
		j = 0;
		if (check_split(str[i], charset) != 0)
			i ++;
		while (check_split(str[i], charset) == 0 && str[i] != 0x00)
		{
			j ++;
			i ++;
		}
		if (j != 0)
		{
			m = -1;
			arr[cnt] = (char *)malloc (sizeof(char) * j + 1);
			while (m++ < j - 1)
				arr[cnt][m] = str[i - j + m];
			arr[cnt++][m] = 0x00;
		}
	}
	return (arr);
}
