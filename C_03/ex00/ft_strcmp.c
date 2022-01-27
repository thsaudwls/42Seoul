/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:14:33 by myson             #+#    #+#             */
/*   Updated: 2022/01/11 14:24:00 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	diff(char *s1, char *s2, int i)
{
	while (i == 0)
	{
		if (*s1 == 0x00 && *s2 == 0x00)
			return (0);
		if (*s1 > *s2)
		{
			i = 1;
			return (1);
		}
		else if (*s1 == *s2)
		{
			s1 ++;
			s2 ++;
		}
		else
		{
			i = -1;
			return (-1);
		}
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	dif;

	i = 0;
	dif = diff(s1, s2, i);
	return (dif);
}
