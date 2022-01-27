/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:09:14 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 17:58:13 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c);
void	ft_print(char new[], int count);
void	minus(int nb, int count);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

int	calcul1(int a, int b, char cal)
{
	if (cal == '+')
		return (a + b);
	else if (cal == '-')
		return (a - b);
	else if (cal == '/')
		return (a / b);
	else
		return (a % b);
}

void	calcul(int a, int b, char cal, int (*f)(int, int, char))
{
	int	val;

	val = 0;
	if (cal == '+' || cal == '-' || cal == '%' || cal == '/')
	{
		if (cal == '/' && b == 0)
		{
			write(1, "Stop : division by zero\n", 24);
			return ;
		}
		else if (cal == '%' && b == 0)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return ;
		}
		val = f(a, b, cal);
	}
	ft_putnbr(val);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 4)
		return (0);
	while (argv[2][i] != 0x00)
		i ++;
	if (i != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	calcul(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0], &calcul1);
	return (0);
}
