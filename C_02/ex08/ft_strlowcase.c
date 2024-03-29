/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:38:18 by myson             #+#    #+#             */
/*   Updated: 2022/01/10 12:45:55 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str != 0x00)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str ++;
	}
	str = tmp;
	return (str);
}
