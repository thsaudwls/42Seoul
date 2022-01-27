/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forth_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:38:37 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 16:29:53 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*b_track_1(int *arr, int i, int len, int block);
int	*b_track_2(int *arr, int i, int len, int block);

int	*back_t1(int *arr, int len, int i)
{
	int	j;
	int	*check3;
	int	*check4;

	check3 = (int *)malloc(sizeof(int) * (len / 4));
	check4 = (int *)malloc(sizeof(int) * (len / 4));
	j = 0;
	check3 = b_track_1(arr, i, len, arr[i]);
	check4 = b_track_2(arr, i, len, arr[i]);
	while (j < len / 4)
	{
		if (check3[j] != 0 || check4[j] != 0)
			check3[j] = 1;
	}
	return (check3);
	free (check4);
	free (check3);
}	

int	*back_t2(int *arr, int len, int i)
{
	int	j;
	int	*check;

	check = (int *)malloc(sizeof(int) * (len / 4));
	j = 0;
	while (i < len)
	{
		if (arr[i] == 0)
		{
			check = back_t1(arr, len, i);
			if (check[j] != 1)
			{	
				arr = back_t2(arr, len, i + 1);
			}
			j ++;
		}	
		i ++;
	}
	free (check);
	return (arr);
}
