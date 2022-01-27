/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:55:02 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 12:38:49 by yejhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int	ft_symbol_check2(char ch, char *buf_malloc, int m)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *) malloc (sizeof(char) * 4);
	while (i < 3)
	{
		new[i] = buf_malloc[m - 3 + i];
		i ++;
	}
	new[i] = 0x00;
	i = 0;
	while (i < 3)
	{
		if (ch == new[i])
		{
			free (new);
			return (0);
		}
		i ++;
	}
	return (1);
}

int	sub_check_valid_number_row(int *cnt, int *t_v, char *buf_malloc)
{
	t_v[0] = buf_malloc[i - 3];
	t_v[1] = buf_malloc[i - 2];
	t_v[2] = buf_malloc[i - 1];
	t_v[3] = NULL;
	while (*cnt < 3)
	{
		if (t_v[cnt] < 32 || t_v[cnt] > 126)
		{
			free (t_v);
			return (0);
		}
		cnt++;
	}
	if (t_v[0] == t_v[1] || t_v[0] == t_v[2] || t_v[1] == t_v[2])
		return (0);
}

int	check_valid_number_row(char *buf_malloc)
{	
	int		i;
	int		j;
	char	*new;
	char	*t_v;
	int		cnt;

	i = 0;
	while (buf_malloc[i] != '\n')
		i ++;
	if (i < 4)
		return (0);
	new = (char *) malloc (sizeof(char) * (i - 3) + 1);
	t_v = (char *) malloc (sizeof(char) * 4);
	cnt = 0;
	if ((sub_check_valid_number_row(&cnt, t_v, buf_malloc)) == 0)
		return (0);
	j = -1;
	while (++j < i - 3)
		new[j] = buf_malloc[j];
	if (ft_atoi(new) <= 0)
		return (0);
	free (new);
	if (ft_atoi(new) != 0)
		return (ft_atoi(new));
	return (0);
}

int	sub_check_valid(char *buf_malloc, int *m, int *i, int *line_cnt)
{
	int	tmp1;
	int	tmp2;
	int	j;

	j = *i;
	tmp1 = 0;
	while (buf_malloc[j] != NULL)
	{
		tmp2 = tmp1;
		tmp1 = 0;
		while (buf_malloc[j++] != '\n')
		{
			if (ft_symbol_check2(buf_malloc[j], buf_malloc, m) != 0)
				return (0);
			tmp1++;
		}
		if (buf_malloc[j++] == '\n')
			*line_cnt++;
		if (line_cnt != 1 && tmp1 != tmp2)
			return (0);
	}
}

int	check_valid(char *buf_malloc)
{
	int	i;
	int	line_cnt;
	int	m;

	line_cnt = 0;
	if (check_valid_number_row(buf_malloc) == 0)
	{
		show_error();
		return (0);
	}
	i = 0;
	tmp1 = 0;
	while (buf_malloc[i] != '\n')
		i ++;
	m = i;
	i ++;
	if (sub_check_valid(buf_malloc, &m, &i, &line_cnt) == 0)
		return (0);
	if (check_valid_number_row(buf_malloc) != line_cnt)
	{
		show_error();
		return (0);
	}
	return (1);
}
