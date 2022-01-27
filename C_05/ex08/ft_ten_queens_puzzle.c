/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:16:37 by myson             #+#    #+#             */
/*   Updated: 2022/01/20 08:19:09 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	exception(int *ten_q, int order)
{
	int	i;

	i = 0;
	if (order == 0)
		return (1);
	while (i < order)
	{
		if (ten_q[i] == ten_q[order])
			return (0);
		else if (i + ten_q[i] == order + ten_q[order])
			return (0);
		else if (i - ten_q[i] == order - ten_q[order])
			return (0);
		i ++;
	}
	return (1);
}

void	print(int *ten_Q)
{
	int		i;
	char	tmp[11];

	i = 0;
	while (i < 10)
	{
		tmp[i] = ten_Q[i] + '0';
		write(1, &tmp[i], 1);
		i ++;
	}
	write(1, "\n", 1);
}

int	finish(int *ten_q)
{
	if (ten_q[0] == 9 && ten_q[1] == 7 && ten_q[2] == 4 && ten_q[3] == 2 && \
			ten_q[4] == 0 && ten_q[5] == 5 && ten_q[6] == 1 && \
			ten_q[7] == 8 && ten_q[8] == 6 && ten_q[9] == 3)
		return (1);
	return (0);
}

int	recursive(int *ten_q, int num, int cnt, int i)
{
	if (num < 10)
	{
		while (i < 10)
		{
			ten_q[num] = i;
			if (exception(ten_q, num))
			{
				if (num == 9)
				{
					print(ten_q);
					cnt ++;
					i = 10;
				}
				cnt = recursive(ten_q, num + 1, cnt, 0);
				if (finish(ten_q) == 1)
					return (cnt);
			}
			else
				i ++;
		}
		if (i == 10)
			cnt = recursive(ten_q, num - 1, cnt, ten_q[num - 1] + 1);
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	ten_q[10];
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < 10)
	{
		ten_q[i] = 0;
		i ++;
	}
	cnt = recursive(ten_q, 0, cnt, 0);
	return (cnt);
}
