/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:42:48 by myson             #+#    #+#             */
/*   Updated: 2022/01/16 16:30:10 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*first(int *num);
int	*up(int *arr, int *num, int len, int i);
int	*down(int *arr, int *num, int len, int i);
int	*left(int *arr, int *num, int len, int i);
int	*right(int *arr, int *num, int len, int i);
int	*find_ud(int *arr, int *num, int i, int len);
int	*find_lr(int *arr, int *num, int i, int len);
int	*back_t2(int *arr, int len, int i);

int	*ft_arr(int *num, int len)
{
	int	*arr1;
	int	*arr2;
	int	*arr;
	int	i;

	i = 0;
	arr = first(num);
	arr1 = up(arr, num, len, i);
	arr2 = down(arr1, num, len, i);
	return (arr2);
}

int	*ft_arr1(int *num, int len)
{
	int	*arr;
	int	*arr1;
	int	*arr2;
	int	i;

	i = 0;
	arr = ft_arr(num, len);
	arr1 = left(arr, num, len, i);
	arr2 = right(arr1, num, len, i);
	return (arr2);
}

int	*ft_arr2(int *num, int len)
{
	int	*arr;
	int	*arr1;
	int	*arr2;
	int	i;

	i = 0;
	arr = ft_arr1(num, len);
	arr1 = find_ud(arr, num, i, len);
	arr2 = find_lr(arr1, num, i, len);
	return (arr2);
}

int	*ft_arr3(int *num, int len)
{
	int	*arr;
	int	*arr1;

	arr = ft_arr2(num, len);
	arr1 = back_t2(arr, len, 0);
	return (arr1);
}
