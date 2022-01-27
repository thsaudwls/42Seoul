/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:15:16 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 11:43:04 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	n;

	if (to_find[0] == 0x00)
		return (str);
	while (*str != 0x00)
	{
		n = 0;
		if (*str == to_find[n])
		{
			while (to_find[n] != 0x00 && str[n] != 0x00)
			{
				if (to_find[n] != str[n])
					break ;
				n ++;
				if (to_find[n] == 0x00)
					return (str);
			}
			n ++;
		}
		str ++;
	}
	return (0x00);
}
