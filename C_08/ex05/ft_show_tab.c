/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:35:51 by myson             #+#    #+#             */
/*   Updated: 2022/01/26 13:11:32 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
	{
		write(1, &str[i], 1);
		i ++;
	}
}

void	ft_putnbr(int nbr)
{
	char	n;

	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		nbr *= (-1);
		write(1, "-", 1);
	}
	if (nbr > 0)
	{
		n = nbr % 10 + '0';
		nbr = nbr / 10;
		ft_putnbr(nbr);
		write(1, &n, 1);
		return ;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i ++;
	}
}
