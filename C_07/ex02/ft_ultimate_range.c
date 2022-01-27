/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 08:50:03 by myson             #+#    #+#             */
/*   Updated: 2022/01/24 14:21:51 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
		return (0x00);
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (*range == 0x00)
		return (-1);
	while (i + min < max)
	{
		(*range)[i] = min + i;
		i ++;
	}
	return (max - min);
}
