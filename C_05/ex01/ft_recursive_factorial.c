/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:25:41 by myson             #+#    #+#             */
/*   Updated: 2022/01/20 20:25:44 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	num;

	num = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	if (nb > 1)
	{
		num *= ft_recursive_factorial(nb - 1);
	}
	return (num);
	return (1);
}
