/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:03:33 by myson             #+#    #+#             */
/*   Updated: 2022/01/23 21:15:30 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_all_check(char *str, char **file_data, int *flag);
int		get_twice_pointer_size(char **str);
int		check_str_valid(char *str);
int		ft_all_check(char *str, char **file_data, int *flag);
void	pre_ft_all_check(char *str, int *flag, char **file_data);
char	*pre2_ft_all_check(char *find, int len);
void	ft_one(char *str, char **file_data, int *flag);
char	*ft_strstr(char *str, char *to_find);

void	print(char *value, char **file_data)
{
	int		i;
	char	*find;
	int		m;

	i = 0;
	m = get_twice_pointer_size(file_data) - 1;
	while (m >= 0)
	{
		find = ft_strstr(file_data[m], value);
		if (find == 0x00)
		{
			m--;
			continue ;
		}
		while (find[i++] != ':')
			;
		i++;
		while (find[i] == ' ')
			i++;
		while (find[i] >= 32 && find[i] <= 126)
			write(1, &find[i++], 1);
		m --;
	}
}

void	pre_ft_hundred(char *one, char *str, char **file_data, int *flag)
{
	one[0] = str[0];
	print(one, file_data);
	write(1, " ", 1);
	print("100", file_data);
	if (str[1] != '0' || str[2] != '0')
	{
		str ++;
		write(1, " ", 1);
		ft_one(str, file_data, flag);
	}
}

void	ft_hundred(char *str, char **file_data, int *flag)
{
	int		len;
	char	*one;
	int		cnt;

	cnt = 0;
	while (*str == '0')
	{
		str ++;
		cnt ++;
	}
	len = ft_strlen(str);
	if (len == 3)
	{
		if (ft_all_check(str, file_data, flag))
			return ;
		one = (char *) malloc (sizeof(char) * 2);
		if (one == 0x00)
			return ;
		pre_ft_hundred(one, str, file_data, flag);
		free (one);
	}
	else
		ft_one(str, file_data, flag);
}

void	ft_thousand(char *str, char **file_data, int *flag)
{
	int		len;
	int		cnt;

	cnt = 0;
	while (*str == '0')
	{
		str ++;
		cnt ++;
	}
	len = ft_strlen(str);
	if (len == 3)
		ft_hundred(str, file_data, flag);
	else if (len == 2 || len == 1)
		ft_one(str, file_data, flag);
}
