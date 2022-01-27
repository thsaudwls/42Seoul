/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:14:01 by myson             #+#    #+#             */
/*   Updated: 2022/01/17 15:24:28 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
	{
		write(1, &str[i], 1);
		i ++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != 0x00 || s2[2] != 0x00)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		else
			i ++;
	}
	return (0);
}

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	m;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				swap(&argv[i], &argv[j]);
			j ++;
		}
		i ++;
	}
	m = 1;
	while (m < argc)
	{
		print(argv[m]);
		m ++;
	}
	return (0);
}
