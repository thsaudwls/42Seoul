/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:52:10 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 17:32:46 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		m;
	int		n;
	char	*tmp;

	m = 0;
	n = 0;
	i = 0;
	while (tab[i] != 0x00)
		i ++;
	while (m < i)
	{
		n = m + 1;
		while (n < i)
		{
			if (cmp(tab[m], tab[n]) > 0)
			{
				tmp = tab[m];
				tab[m] = tab[n];
				tab[n] = tmp;
			}
			n ++;
		}
		m ++;
	}
}
