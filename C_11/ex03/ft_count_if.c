/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:57:41 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 17:27:55 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	m;
	int	cnt;

	m = 0;
	cnt = 0;
	while (m < length)
	{
		if (f(tab[m]) != 0)
			cnt ++;
		m ++;
	}
	return (cnt);
}
