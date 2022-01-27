/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:46:15 by myson             #+#    #+#             */
/*   Updated: 2022/01/08 10:42:08 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char new[], int count)
{
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		write(1, &new[i], 1);
		i --;
	}
}

void	minus(int nb, int count)
{
	char	new2[11];

	putchar('-');
	nb = nb * (-1);
	while (nb > 0)
	{
		new2[count] = nb % 10 + 48;
		nb = nb / 10;
		count ++;
	}
	ft_print(new2, count);
}

void	ft_putnbr(int nb)
{
	int		count;
	char	ne[11];

	count = 0;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
		minus(nb, count);
	else if (nb > 0)
	{
		while (nb > 0)
		{
			ne[count] = nb % 10 + 48;
			nb = nb / 10;
			count ++;
		}
		ft_print(ne, count);
	}
	else
		putchar('0');
}
