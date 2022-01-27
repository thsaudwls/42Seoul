/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:08:58 by myson             #+#    #+#             */
/*   Updated: 2022/01/20 10:30:08 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	num = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
	{
		while (nb >= 1)
		{
			num *= nb;
			nb --;
		}
	}
	return (num);
}
