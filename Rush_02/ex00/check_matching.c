/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matching.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:54:45 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/23 21:11:07 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
void	print(char *value, char **file_data);
char	*ft_strstr(char *str, char *to_find);

char	*pre2_ft_all_check(char *find, int len)
{
	if (find != 0x00)
	{
		find += len;
		while (*find == ' ')
			find ++;
		if (*find == ':')
			find ++;
		while (*find == ' ')
			find ++;
		while (*find >= 32 && *find <= 126)
		{
			write(1, find, 1);
			find ++;
		}
	}
	return (find);
}

void	pre_ft_all_check(char *str, int *flag, char **file_data)
{
	char	*one;
	int		i;

	i = 1;
	while (str[i] == '0')
		i ++;
	if (i == ft_strlen(str) && *flag == 1)
	{
		one = (char *) malloc (sizeof(char) * 2);
		if (one == 0x00)
			return ;
		one[0] = '1';
		one[1] = '\0';
		print(one, file_data);
		*flag = 0;
		write(1, " ", 1);
		free (one);
	}
	else
	{
		*flag = 1;
	}
}

int	ft_all_check(char *str, char **file_data, int *flag)
{
	char	*find;
	int		len;
	int		m;

	len = ft_strlen(str);
	if ((len % 3 == 1 || len % 3 == 0) && str[0] == '1' && len != 1)
		pre_ft_all_check(str, flag, file_data);
	m = 0;
	while (file_data[m] != 0x00)
	{
		find = ft_strstr(file_data[m], str);
		if (find != 0x00)
			break ;
		m ++;
	}
	find = pre2_ft_all_check(find, len);
	if (find != 0x00)
		return (len);
	else
		return (0);
}
