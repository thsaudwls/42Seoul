/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:08 by myson             #+#    #+#             */
/*   Updated: 2022/01/10 09:41:03 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	count;

	count = 0;
	while (*str != 0x00 && count == 0)
	{
		if (*str >= 'a' && *str <= 'z')
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
