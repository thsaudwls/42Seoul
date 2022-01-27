/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:43:44 by myson             #+#    #+#             */
/*   Updated: 2022/01/10 14:05:02 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	count;

	count = 0;
	while (*str != 0x00 && count == 0)
	{
		if (*str >= 32 && *str <= 126)
			str ++;
		else
		{
			count = 1;
			str ++;
		}
	}
	if (count == 0)
		return (1);
	else
		return (0);
}
