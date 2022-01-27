/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:38:31 by myson             #+#    #+#             */
/*   Updated: 2022/01/18 15:32:30 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
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
	return (1);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
		i ++;
	return (i);
}

int	atoi(char *str)
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

int	ft_atoi_base(char *str, char *base)
{
	int	p_m;
	int	ret;

	ret = 0;
	if (!(check_base(base)))
		return (0);
	p_m = atoi(str);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str ++;
	while (*str == '+' || *str == '-')
		str ++;
	while (*str != 0x00)
	{
		if (change(base, *str) >= 0)
		{
			if (ret != 0)
				ret *= ft_len(base);
			ret += change(base, *str);
		}
		else
			return (ret * p_m);
		str ++;
	}
	return (ret * p_m);
}
