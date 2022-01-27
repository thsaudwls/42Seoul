/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:42:33 by myson             #+#    #+#             */
/*   Updated: 2022/01/10 09:43:14 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	count;

	count = 0;
	while (*str != 0x00 && count == 0)
	{
		if (*str >= 'A' && *str <= 'Z')
			str ++;
		else
		{
			str ++;
			count = 1;
		}
	}
	if (count == 0)
		return (1);
	else
		return (0);
}
