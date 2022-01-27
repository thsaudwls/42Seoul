/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:38:01 by myson             #+#    #+#             */
/*   Updated: 2022/01/12 15:23:16 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char m1, char m2, char m3, char m4)
{
	write(1, &m1, 1);
	write(1, &m2, 1);
	if (m3 != 'k')
		write(1, &m3, 1);
	if (m4 != 'r')
		write(1, &m4, 1);
}

void	ft_circit(char n1, char n2, char n3, char n4)
{
	if (n2 == '9')
	{
		n3 = n1 + 1;
	}
	else
	{
		n3 = n1;
		n4 = n2 + 1;
	}
	while (n3 <= '9')
	{
		while (n4 <= '9')
		{
			ft_print(n1, n2, ' ', 'r');
			if (n1 == '9' && n2 == '8' && n3 == '9' && n4 == '9')
				ft_print(n3, n4, 'k', 'r');
			else
				ft_print(n3, n4, ',', ' ');
			n4 ++;
		}
		n3 ++;
		n4 = '0';
	}
}

void	ft_print_comb2(void)
{
	char	n1;
	char	n2;
	char	n3;
	char	n4;

	n1 = '0';
	n2 = '0';
	n3 = '0';
	n4 = '0';
	while (n1 <= '9')
	{
		n2 = '0';
		while (n2 <= '9')
		{
			ft_circit(n1, n2, n3, n4);
			n2 ++;
		}
		n1 ++;
	}
}
