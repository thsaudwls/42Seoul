/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_get_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:05:03 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/23 21:13:05 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	show_error(void);
char	**sort_dict(char *file_data);
int		ft_strlen(char *str);
char	*strdup_file_data(char *src, int buf_size);
int		get_twice_pointer_size(char **str);
int		get_word_count(char *str, char *charset);
void	ft_all(char *str, char **file_data, int len);

void	normal_dict(char **argv, int fd)
{
	char	buff[1000000];
	char	*file_data;	
	int		buf_size;
	char	**sorted_dict;
	int		i;

	fd = open("./numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Dict Error", 11);
		return ;
	}
	buf_size = read(fd, buff, 1000000);
	file_data = strdup_file_data(buff, buf_size);
	close(fd);
	sorted_dict = sort_dict(file_data);
	free(file_data);
	ft_all(argv[1], sorted_dict, ft_strlen(argv[1]));
	i = -1;
	while (++i < get_twice_pointer_size(sorted_dict) + 1)
		free(sorted_dict[i]);
	free(sorted_dict);
}

char	*strdup_file_data(char *src, int buf_size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * buf_size + 1);
	if (dest == 0)
	{
		return (0);
	}
	while (i < buf_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_is_seprate(char str, char *charset)
{
	int	i;

	i = 0;
	while (i < ft_strlen(charset))
	{
		if (str == charset[i] || str == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_split(char *str, char *charset, int *start_point)
{
	char	*tmp_arr;
	int		i;
	int		j;

	i = *start_point;
	while (str[i] != '\0')
	{
		if (ft_is_seprate(str[i], charset) == 0
			&& ft_is_seprate(str[(i++) + 1], charset) == 1)
			break ;
	}
	tmp_arr = malloc(sizeof(char) * (i - *start_point) + 2);
	j = 0;
	while (*start_point < i)
	{
		tmp_arr[j] = str[*start_point];
		*start_point += 1;
		j++;
	}
	tmp_arr[j++] = '\n';
	tmp_arr[j] = '\0';
	return (tmp_arr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		start_point;
	char	**arr;

	start_point = 0;
	arr = malloc(sizeof(char *) * get_word_count(str, charset) + 1);
	i = 0;
	while (i < get_word_count(str, charset))
	{
		while (ft_is_seprate(str[start_point], charset) == 1)
		{
			start_point++;
		}
		arr[i] = ft_strdup_split(str, charset, &start_point);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
