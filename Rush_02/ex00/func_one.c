/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:57:52 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/23 21:21:44 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print(char *value, char **file_data);
int		ft_strlen(char *str);
int		ft_all_check(char *str, char **file_data, int *flag);

void	pre_ft_one(int len, char *str, char **file_data)
{
	if (len == 0)
		return ;
	if (len == 1 || (len == 2 && *str == '1'))
		print(str, file_data);
}

void	pre2_ft_one(char *str, char **file_data, char *second)
{
	second[0] = str[0];
	second[1] = '0';
	print(second, file_data);
	if (str[1] != '0')
	{
		write(1, " ", 1);
		print(&str[1], file_data);
	}
}

void	ft_one(char *str, char **file_data, int *flag)
{
	int		len;
	char	*second;
	int		cnt;

	cnt = 0;
	while (*str == '0')
	{
		str ++;
		cnt ++;
	}
	len = ft_strlen(str);
	second = (char *) malloc (sizeof(char) * 3);
	if (second == 0x00)
		return ;
	pre_ft_one(len, str, file_data);
	if (len == 2 && *str != '1')
	{
		if (ft_all_check(str, file_data, flag) != 0)
		{
			free (second);
			return ;
		}
		pre2_ft_one(str, file_data, second);
	}
	free (second);
}

void	ft_num_left_big(int i, char **after_split)
{
	char	*tmp;

	tmp = after_split[i];
	after_split[i] = after_split[i + 1];
	after_split[i + 1] = tmp;
}
