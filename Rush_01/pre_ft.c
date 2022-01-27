/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:24:16 by myson             #+#    #+#             */
/*   Updated: 2022/01/15 14:40:49 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	ft_atoi(char *str)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <='9')
		{
			while (str[i] != '\0')
			{
				result *= 10;
				result += str[i] - '0';
				i++;
			}
		}
		else
			return (-1);
	}
	return (result);
}
*/

char	*delete_sp(char *str)
{
	int	*num;
	int	len;
	int	i;
	int	j;

	len = 0;
	while (str[len] != 0x00)
		len ++;
	len = len / 2 + 1;
	num = (int *)malloc(sizeof(int) * len);
	i = 0;
	j = 0;
	while (i < len)
	{
		num[i] = str[j] - '0';
		i ++;
		j += 2;
	}
}
