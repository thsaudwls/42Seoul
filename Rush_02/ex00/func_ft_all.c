/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ft_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:12:20 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/23 21:12:30 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_thousand(char *str, char **file_data, int *flag);
int		ft_strlen(char *str);
void	print(char *value, char **file_data);
int		check_str_valid(char *str);
int		ft_all_check(char *str, char **file_data, int *flag);
char	*next_str(char *str, int mod);

void	pre_ft_all(int mod, char **file_data, int *flag, char *str)
{
	int		i;
	char	*leng;

	i = 0;
	leng = (char *) malloc (sizeof(char) * (mod + 1));
	while (i < mod)
	{
		leng[i] = str[i];
		i ++;
	}
	leng[i] = 0x00;
	ft_thousand(leng, file_data, flag);
	free (leng);
}

void	pre2_ft_all(int mod, char **file_data, int cnt, char *str)
{
	char	*leng;
	int		i;

	leng = (char *) malloc(sizeof(char) * (ft_strlen(str) - mod + 2));
	leng[0] = '1';
	i = 1;
	while (i < ft_strlen(str) - mod + 1)
		leng[i++] = '0';
	leng[i] = 0x00;
	print(leng, file_data);
	while (cnt <= ft_strlen(str))
	{
		if (str[cnt] == '0')
			cnt ++;
		else
			break ;
	}
	i = 0;
	cnt = 0;
	while (cnt ++ < ft_strlen(str) - mod)
		if (str[mod + i] == '0')
			i ++;
	if (i < ft_strlen(str) - mod)
		write(1, " ", 1);
	free (leng);
}

void	ft_all(char *str, char **file_data, int len)
{
	int		mod;
	int		flag;
	int		cnt;

	cnt = 0;
	flag = 1;
	if (len > 0)
	{
		if (ft_all_check(str, file_data, &flag) != 0)
			return ;
		mod = len % 3;
		if (mod == 0)
			mod = 3;
		pre_ft_all(mod, file_data, &flag, str);
		if (len > mod && check_str_valid(str) == 0)
		{
			write(1, " ", 1);
			pre2_ft_all(mod, file_data, cnt, str);
		}
		if (len > mod)
		{
			str = next_str(str, mod);
			ft_all(str, file_data, len - mod);
		}
	}
}
