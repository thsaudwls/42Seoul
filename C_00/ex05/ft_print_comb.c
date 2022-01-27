/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:08:36 by myson             #+#    #+#             */
/*   Updated: 2022/01/12 12:22:05 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_circit(char a, char b, char c, char d)
{
	char	sp;

	sp = 32;
	while (a <= 55)
	{
		b = a;
		while (++b <= 56)
		{
			c = b;
			while (++c <= 57)
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (a != 55)
				{
					write(1, &d, 1);
					write(1, &sp, 1);
				}
			}
		}
		a ++;
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	d = 44;
	a = 48;
	c = '0';
	b = '0';
	ft_circit(a, b, c, d);
}
