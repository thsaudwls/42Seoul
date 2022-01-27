/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:29:13 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 17:15:02 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	p_m;
	int	ret;

	p_m = 1;
	ret = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str ++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p_m *= (-1);
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ret != 0)
			ret *= 10;
		ret += (*str - '0');
		str ++;
	}
	return (ret * p_m);
}