/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 08:28:05 by myson             #+#    #+#             */
/*   Updated: 2022/01/24 14:04:50 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (0x00);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == 0x00)
		return (0x00);
	while (i + min < max)
	{
		arr[i] = min + i;
		i ++;
	}
	return (arr);
}
