/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:20:38 by myson             #+#    #+#             */
/*   Updated: 2022/01/20 10:59:15 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	tmp_nb;

	tmp_nb = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		power --;
		if (power == 0)
			return (nb);
		nb *= tmp_nb;
		ft_recursive_power(nb, power);
	}
	return (nb);
}
