/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:13:54 by myson             #+#    #+#             */
/*   Updated: 2022/01/23 21:14:41 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_all(char *str, char **file_data, int len);
char	*next_str(char *str, int mod);
void	ft_thousand(char *str, char **file_data);
void	ft_hundred(char *str, char **file_data);
void	ft_one(char *str, char **file_data);
void	print(char *value, char **file_data);
char	*ft_strstr(char *str, char *to_find);
int		ft_all_check(char *str, char **file_data, int *flag);
void	show_error(void);
void	check_many_zero(int argc, char **argv);
int		check_input_num(int argc, char **argv);
int		get_twice_pointer_size(char **str);
int		ft_num_len(char *num);
int		get_word_count(char *str, char *charset);
int		ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
char	*strdup_file_data(char *src, int buf_size);
void	normal_dict(char **argv, int fd);
void	ft_num_left_big(int i, char **after_split);

void	ft_num_same(int i, char **after_split)
{
	int		k;
	char	*tmp;

	k = 0;
	while (after_split[i][k] != ':')
	{
		if (after_split[i][k] > after_split[i + 1][k])
		{
			tmp = after_split[i];
			after_split[i] = after_split[i + 1];
			after_split[i + 1] = tmp;
			break ;
		}
		else if (after_split[i][k] == after_split[i + 1][k])
		{
			k++;
			continue ;
		}
		else
		{
			break ;
		}
	}
}

char	**sort_dict(char *file_data)
{
	char	**after_split;
	int		i;
	int		after_split_size;
	int		j;

	j = 0;
	after_split = ft_split(file_data, "\n");
	after_split_size = get_twice_pointer_size(after_split);
	while (j < after_split_size - 1)
	{
		i = j;
		while (i < after_split_size - 1)
		{
			if (ft_num_len(after_split[i]) > ft_num_len(after_split[i + 1]))
				ft_num_left_big(i, after_split);
			else if (ft_num_len(after_split[i])
				== ft_num_len(after_split[i + 1]))
				ft_num_same(i, after_split);
			i++;
		}
		j++;
	}
	i = 0;
	return (after_split);
}

char	*get_filename(char **argv)
{
	char	*file_name;
	int		i;

	file_name = malloc(sizeof(char) * (ft_strlen(argv[1]) + 3));
	file_name[0] = '.';
	file_name[1] = '/';
	i = 0;
	while (argv[1][i] != '\0')
	{
		file_name[i + 2] = argv[1][i];
		i++;
	}
	file_name[i + 2] = '\0';
	return (file_name);
}

void	new_dict(char **argv, int fd, char	*file_name)
{
	char	buff[1000000];
	int		buf_size;
	char	*file_data;	
	char	**sorted_dict;
	int		i;

	file_name = get_filename(argv);
	fd = open(file_name, O_RDONLY);
	free(file_name);
	if (fd < 0)
	{
		write(1, "Dict Error", 11);
		return ;
	}
	buf_size = read(fd, buff, 1000000);
	file_data = strdup_file_data(buff, buf_size);
	close(fd);
	sorted_dict = sort_dict(file_data);
	ft_all(argv[2], sorted_dict, ft_strlen(argv[2]));
	free(file_data);
	i = -1;
	while (++i < get_twice_pointer_size(sorted_dict) + 1)
		free(sorted_dict[i]);
	free(sorted_dict);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*file_name;

	fd = 0;
	file_name = 0;
	check_many_zero(argc, argv);
	if (check_input_num(argc, argv) == 1)
	{
		if (argc == 2)
			normal_dict(argv, fd);
		else if (argc == 3)
			new_dict(argv, fd, file_name);
		else
		{
			show_error();
			write(1, "\n", 1);
			return (0);
		}
	}
	else if (argc == 1)
		show_error();
	else
		write(1, "Error", 5);
	write(1, "\n", 1);
	return (0);
}
