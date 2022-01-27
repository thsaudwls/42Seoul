/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:55:54 by myson             #+#    #+#             */
/*   Updated: 2022/01/25 16:08:15 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == 0x00 || base[1] == 0x00)
		return (0);
	while (base[i] != 0x00)
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ' || \
				(base[i] >= 9 && base[i] <= 13))
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

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
		i ++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	p_m;

	p_m = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str ++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p_m *= (-1);
		str ++;
	}
	return (p_m);
}

int	change(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != 0x00)
	{
		if (base[i] == c)
			return (i);
		i ++;
	}
	return (-1);
}

int	base_to_int(char *nbr, char *base_from)
{
	int	p_m;
	int	ret;

	ret = 0;
	p_m = ft_atoi(nbr);
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr ++;
	while (*nbr == '+' || *nbr == '-')
		nbr ++;
	while (*nbr != 0x00)
	{
		if (change(base_from, *nbr) >= 0)
			ret = ret * ft_len(base_from) + change(base_from, *nbr);
		else
			return (ret * p_m);
		nbr ++;
	}
	return (ret * p_m);
}
