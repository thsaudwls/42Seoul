/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:27:00 by myson             #+#    #+#             */
/*   Updated: 2022/01/11 08:26:19 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	count;

	count = 0;
	while (*str != 0x00 && count == 0)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
		{
			count = 1;
			str++;
		}
	}
	if (count == 0)
		return (1);
	else
		return (0);
}
