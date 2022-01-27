/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:24:16 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 17:04:03 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*delete_sp(char *str)
{
	int	*num;
	int	len;
	int	i;
	int	j;

	len = 0;
	while (str[len] != 0x00)
		len ++;
	len = len / 2 + 1;
	num = (int *)malloc(sizeof(int) * len);
	i = 0;
	j = 0;
	while (i < len)
	{
		num[i] = str[j] - '0';
		i ++;
		j += 2;
	}
	return (num);
	free (num);
}
