/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_find_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:15:37 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/23 21:11:56 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

char	*next_str(char *str, int mod)
{
	int	i;

	i = 0;
	while (i < mod)
	{
		str ++;
		i ++;
	}
	return (str);
}

int	ft_strstr_sub(int size, char *to_find, char *str, int cnt)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == to_find[i])
		{
			cnt ++;
			i ++;
		}
		else
			return (0x00);
	}
	return (cnt);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	cnt;
	int	i;
	int	size;

	len = ft_strlen(to_find);
	i = 0;
	while (str[i] == ' ')
		i++;
	cnt = 0;
	size = 0;
	while (str[size + i] != ' ' && str[size + i] != ':')
	{
		size++;
	}
	if (ft_strlen(to_find) != size)
	{
		return (0x00);
	}
	cnt = ft_strstr_sub(size, to_find, str + i, cnt);
	if (cnt == len)
		return (str + i);
	else
		return (0x00);
}
