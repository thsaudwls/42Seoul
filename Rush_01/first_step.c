/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:41:23 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 21:44:47 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*first(int *num)
{
	int			i;
	int			j;
	int			len;
	static int	*arr;
	int			cnt;

	len = 0;
	i = 0;
	cnt = 1;
	while (num[len] != 0x00)
		len++;
	arr = (int *) malloc (sizeof(int) * len);
	return (arr);
	free (arr);
}

int	*up(int *arr, int *num, int len, int i)
{
	while (i < len)
	{
		if (num[i] == len / 4)
		{
			if (i < len / 4)
			{
				while (i < len)
				{
					arr[i] = 1 + i / (len / 4);
					i += len / 4;
				}
			}
		}
		i ++;
	}
	return (arr);
}

int	*down(int *arr, int *num, int len, int i)
{
	while (i < len)
	{
		if (num[i] == len / 4)
		{
			if (i >= len / 4 && i < len / 2)
			{
				while (i - len / 4 < len)
				{
					if (arr[i - len / 4] != 0)
						return (0x00);
					arr[i - len / 4] = 5 - i / (len / 4);
					i += len / 4;
				}
			}
		}
		i ++;
	}
	return (arr);
}

int	*left(int *arr, int *num, int len, int i)
{
	int	j;

	j = 0;
	while (i < len)
	{
		if (num[i] == len / 4)
		{
			if (i >= len / 2 && i < 3 * (len / 4))
			{
				while (j < 4)
				{
					if ((i / (len / 4) - 1) != arr[(i - len / 2) * (len / 4)] \
							&& arr[(i - len / 2) * (len / 4)] != 0)
						return (0x00);
					arr[(i - len / 2) * (len / 4) + j] = i / (len / 4) - 1;
					j++;
				}
			}
		}
		i ++;
	}
	return (arr);
}

int	*right(int *arr, int *num, int len, int i)
{
	int	j;

	j = 0;
	while (i < len && i - 3 * (len / 4) * (len / 4))
	{
		if (i > 3 * (len / 4))
		{
			if ((7 - i / (len / 4)) != arr[(i - 3 * (len / 4)) * (len / 4)] && \
					arr[(i - 3 * (len / 4)) * (len / 4)] != 0)
				return (0x00);
			arr[(i - 3 * (len / 4)) * (len / 4) + j] = 7 - i / (len / 4);
			j ++;
		}	
		i ++;
	}
	return (arr);
}
