/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:23:59 by myson             #+#    #+#             */
/*   Updated: 2022/01/20 11:11:34 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb >= 2147395600)
		return (46341);
	while (i <= nb / 2 && i < 46345)
	{
		if (nb <= i * i)
			return (i);
		i ++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	sq;
	int	i;

	i = 2;
	sq = ft_sqrt(nb);
	if (nb <= 1)
		return (0);
	while (i <= sq)
	{
		if (nb % i == 0)
			return (0);
		i ++;
	}
	return (1);
}
