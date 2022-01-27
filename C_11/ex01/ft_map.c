/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:51:53 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 17:12:43 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new;
	int	i;

	i = 0;
	new = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		new[i] = f(tab[i]);
		i ++;
	}
	return (new);
}
