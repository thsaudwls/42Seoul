/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:45:54 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 16:33:55 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*init(int *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
	{
		str[i] = 0;
		i ++;
	}
	return (str);
}

int	*b_track_1(int *arr, int i, int len, int block)
{
	int	*check1;
	int	n_mod;
	int	count;

	count = 1;
	check1 = (int *) malloc(sizeof(int) * (len / 4));
	check1 = init(check1);
	if (block == 0)
	{
		n_mod = i % (len / 4);
		while (count <= (len / 4))
		{
			while (n_mod < len)
			{
				if (count == arr[n_mod])
					check1[count - 1] = 1;
				n_mod += (len / 4);
			}
			count ++;
		}
		return (check1);
	}
	return (0x00);
	free (check1);
}

int	*b_track_2(int *arr, int i, int len, int block)
{
	int	*check2;
	int	n_div;
	int	count;

	count = 1;
	check2 = (int *) malloc(sizeof(int) * (len / 4));
	check2 = init(check2);
	if (block == 0)
	{
		n_div = i / (len / 4);
		while (count <= (len / 4))
		{
			while (n_div * (len / 4) < len)
			{
				if (count == arr[n_div])
					check2[count - 1] = 1;
				n_div ++;
			}
			count ++;
		}
		return (check2);
	}
	return (0x00);
	free (check2);
}
