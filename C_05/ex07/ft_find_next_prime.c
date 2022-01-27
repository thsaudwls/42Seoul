/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:36:20 by myson             #+#    #+#             */
/*   Updated: 2022/01/19 09:31:49 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb >= 2147395600)
		return (46341);
	while (i <= nb / 2 && i < 46341)
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

	sq = ft_sqrt(nb);
	if (nb <= 1)
		return (0);
	while (sq > 1)
	{
		if (nb % sq == 0)
			return (0);
		sq --;
	}
	return (1);
}

int	ft_next(int nb)
{
	int	a;

	while (1)
	{
		a = ft_is_prime(nb);
		if (a == 1)
			return (nb);
		nb ++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	val;

	if (nb <= 2)
		return (2);
	val = ft_next(nb);
	return (val);
}
