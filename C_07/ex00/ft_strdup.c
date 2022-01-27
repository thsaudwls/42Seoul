/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:37:16 by myson             #+#    #+#             */
/*   Updated: 2022/01/24 14:22:01 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (src[i] != 0x00)
		i ++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == 0x00)
		return (0x00);
	while (j < i)
	{
		str[j] = src[j];
		j ++;
	}
	str[j] = 0x00;
	return (str);
}
