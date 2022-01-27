/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:54:04 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 17:27:03 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*find_ud(int *arr, int *num, int i, int len)
{
	while (i < len / 2)
	{
		if (num[i] == 1)
		{
			if (i < len / 4)
			{
				if ((arr[i] != (len / 4)) && (arr[i] != 0) && (arr[i] != 0x00))
					return (0x00);
				arr[i] = len / 4;
			}
			else if (i < len / 2)
			{
				if (arr[i + len / 2] != len / 4 && arr[i + len / 2] != 0)
					return (0x00);
				arr[i + len / 2] = len / 4;
			}
		}
		i ++;
	}
	return (arr);
}

int	*find_lr(int *arr, int *num, int i, int len)
{
	while (i < len)
	{
		if (num[i] == 1)
		{
			if (i >= len / 2 && i < 3 * (len / 4))
			{
				if (arr[(i - len / 2) * len / 4] != len / 4 && \
						arr[(i - len / 2) * len / 4] != 0)
					return (0x00);
				arr[(i - len / 2) * len / 4] = len / 4;
			}
			else if (i >= 3 * (len / 4))
			{
				if (arr[(i - 3 * (len / 4)) * (len / 4) + 3] != len / 4 && \
						arr[(i - 3 * (len / 4)) * (len / 4) + 3] != 0)
					return (0x00);
				arr[i - 3 * (len / 4) + 3] = len / 4;
			}
		}
		i ++;
	}
	return (arr);
}
