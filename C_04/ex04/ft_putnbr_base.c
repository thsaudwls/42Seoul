/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:37:39 by myson             #+#    #+#             */
/*   Updated: 2022/01/19 08:23:23 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == 0x00 || base[1] == 0x00)
		return (0);
	while (base[i] != 0x00)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i - 1;
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (0);
			j --;
		}
		i ++;
	}
	return (i);
}

void	print(int radix, long long n, char *base)
{
	long long	ret;

	if (n > 0)
	{
		ret = n % radix;
		n = n / radix;
		print(radix, n, base);
		write(1, &base[ret], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			radix;
	int			i;
	long long	n;

	i = 0;
	radix = check_base(base);
	if (radix == 0)
		return ;
	n = (long long)nbr;
	if (n < 0)
	{
		n *= (-1);
		write(1, "-", 1);
	}
	if (nbr == 0)
		write(1, &base[0], 1);
	print(radix, n, base);
}
