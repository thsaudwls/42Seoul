/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 08:47:45 by myson             #+#    #+#             */
/*   Updated: 2022/01/12 11:26:09 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int num[], int size)
{
	int		i;
	char	c;
	char	sp;
	char	comma;

	i = 0;
	sp = ' ';
	comma = ',';
	while (i < size)
	{
		c = num[i] + '0';
		write(1, &c, 1);
		i ++;
	}
	if (num[size - 1] != 9 || num[0] != 10 - size)
	{
		write(1, &comma, 1);
		write(1, &sp, 1);
	}
}

void	main_algo(int n, int m, int i, int first_num[])
{
	int	j;

	while (first_num[n - i] <= m - i + 1)
	{
		if (i == 1)
		{
			ft_print(first_num, n);
			first_num[n - 1]++;
		}
		else
		{
			j = 1;
			main_algo(n, m, i - 1, first_num);
			first_num[n - i]++;
			while (j < i)
			{
				first_num[n - i + j] = first_num[n - i] + j;
				j ++;
			}
		}
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	first_num[9];

	i = 0;
	while (i < n)
	{
		first_num[i] = i;
		i ++;
	}
	main_algo(n, 9, n, first_num);
}
