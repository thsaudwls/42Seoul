/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:00:17 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 17:29:20 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	cnt;
	int	cnt2;

	i = 0;
	cnt = 0;
	cnt2 = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (f(tab[i], tab[j]) < 0)
				cnt ++;
			if (f(tab[i], tab[j]) > 0)
				cnt2 ++;
			j++;
		}
		i++;
	}
	if (cnt == 0 || cnt2 == 0)
		return (1);
	else
		return (0);
}
