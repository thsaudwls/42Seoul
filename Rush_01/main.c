/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:07:02 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 19:54:52 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*delete_sp(char *str);
int	*ft_arr3(int *num, int len);

void	print_array(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < len / 4)
	{
		i = 0;
		while (i < len / 4)
		{
			write(1, &arr[i + j * (len / 4)], 1);
			if (i != len / 4 - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			i ++;
		}
		j ++;
	}
}

int	main(int argc, char **argv)
{
	int	*array;
	int	*index;
	int	len;
	int	len_square;
	int	i;

	len_square = 16;
	len = 16;
	array = (int *)malloc(sizeof(int) * len_square);
	index = (int *)malloc(sizeof(int) * len);
	i = 0;
	index = delete_sp(argv[1]);
	while (index[i] != 0x00)
	{
		if (index[i] < '0' || index[i] > (len / 4))
			write(1, "Error", 6);
		i ++;
	}
	array = ft_arr3(index, len);
	print_array(array, len / 4);
	free (index);
	free(array);
}
