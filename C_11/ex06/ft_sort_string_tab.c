/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:39:35 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 17:54:02 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && !(s1[i] == 0x00 && s2[i] == 0x00))
		i ++;
	return (s1[i] - s2[i]);
}

void	ft_sort(char **s1, char **s2, int (*f) (char *, char *))
{
	char	*tmp;

	if (f(*s1, *s2) > 0)
	{
		tmp = *s1;
		*s1 = *s2;
		*s2 = tmp;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	m;
	int	n;

	i = 0;
	m = 0;
	while (tab[i] != 0x00)
		i++;
	while (m < i)
	{
		n = m + 1;
		while (n < i)
		{
			ft_sort(&(tab[m]), &(tab[n]), &ft_strcmp);
			n ++;
		}
		m ++;
	}
}
