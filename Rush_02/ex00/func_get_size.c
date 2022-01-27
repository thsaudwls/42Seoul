/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_get_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:00:30 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/23 21:13:26 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_seprate(char str, char *charset);

int	get_twice_pointer_size(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_num_len(char *num)
{
	int	i;

	i = 0;
	while (num[i] != ':')
	{
		i++;
	}
	return (i);
}

int	get_word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_is_seprate(str[i], charset) == 0
			&& (ft_is_seprate(str[i + 1], charset) == 1 || str[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

void	show_error(void)
{
	write(1, "error", 5);
}
