/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:03:34 by myson             #+#    #+#             */
/*   Updated: 2022/01/26 08:49:18 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
int		ft_len(char *str);
int		ft_atoi(char *str);
int		change(char *base, char c);
int		base_to_int(char *nbr, char *base_from);
int		check_radix(long int val, int base_to_len);
char	*change_m(long int val, int cnt, int base_to_len, char *base_to);
char	*change_p(long int val, int cnt, int base_to_len, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	val;
	int			base_to_len;
	int			cnt;
	char		*tmp;

	cnt = 0;
	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0x00);
	base_to_len = ft_len(base_to);
	val = base_to_int(nbr, base_from);
	cnt = check_radix(val, base_to_len);
	if (val < 0)
		tmp = change_m(val, cnt, base_to_len, base_to);
	else
		tmp = change_p(val, cnt, base_to_len, base_to);
	return (tmp);
}

int	check_radix(long int val, int base_to_len)
{
	int	cnt;

	cnt = 0;
	if (val < 0)
		val *= (-1);
	if (val == 0)
		cnt = 1;
	while (val > 0)
	{
		val = val / base_to_len;
		cnt ++;
	}
	return (cnt);
}

char	*change_m(long int val, int cnt, int base_to_len, char *base_to)
{
	char	*tmp;
	int		i;
	int		cnt2;

	i = 0;
	cnt2 = cnt;
	val *= (-1);
	tmp = (char *) malloc (sizeof(char) * (cnt + 2));
	if (tmp == 0x00)
		return (0x00);
	tmp[0] = '-';
	while (cnt > 0)
	{
		tmp[cnt] = base_to[(val % base_to_len)];
		val = val / base_to_len;
		cnt --;
	}
	tmp[cnt2 + 1] = 0x00;
	return (tmp);
}

char	*change_p(long int val, int cnt, int base_to_len, char *base_to)
{
	char	*tmp;
	int		i;
	int		cnt2;

	i = 0;
	cnt2 = cnt;
	tmp = (char *) malloc(sizeof(char) * (cnt + 1));
	if (tmp == 0x00)
		return (0x00);
	while (cnt > 0)
	{
		tmp[cnt - 1] = base_to[(val % base_to_len)];
		val = val / base_to_len;
		cnt --;
	}
	tmp[cnt2] = 0x00;
	return (tmp);
}
