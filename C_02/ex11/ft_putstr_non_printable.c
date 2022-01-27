/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:42:36 by myson             #+#    #+#             */
/*   Updated: 2022/01/11 09:43:53 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (*str != 0x00)
	{
		i ++;
		str ++;
	}
	return (i);
}

void	putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	trans(unsigned char c)
{
	char	n1;
	char	n2;

	n1 = c / 16 + '0';
	if (n1 > '9')
		n1 += 39;
	n2 = c % 16 + '0';
	if (n2 > '9')
		n2 += 39;
	putchar('\\');
	putchar(n1);
	putchar(n2);
}

void	ft_putstr_non_printable(char *str)
{
	int				len;
	int				i;
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	i = 0;
	len = ft_len(str);
	while (i < len)
	{
		if (*tmp >= 32 && *tmp <= 126)
		{
			putchar(*tmp);
			tmp ++;
		}
		else
		{
			trans(*tmp);
			tmp ++;
		}
		i ++;
	}
}
