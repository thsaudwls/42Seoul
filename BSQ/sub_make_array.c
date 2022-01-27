/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_make_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:28:40 by myson             #+#    #+#             */
/*   Updated: 2022/01/27 12:29:06 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**result(int **map, int *xy, char *symbol)
{
	char	**result_array;
	int		i;
	int		j;

	i = 0;
	result_array = (char **) malloc (sizeof(char *) * (xy[1] + 1));
	while (i < xy[1])
	{
		j = 0;
		result_array[i] = (char *) malloc (sizeof(char) * (xy[0] + 1));
		while (j < x)
		{
			if (map[i][j] <= 0 && map[i][j] != -2)
				result_array[i][j] = symbol[1];
			else if (map[i][j] == -2)
				result_array[i][j] = symbol[2];
			else
				result_array[i][j] = symbol[0];
			j ++;
		}
		i ++;
	}
	return (result_array);
}

char	*symbol_check(char *buf)
{
	char	*symbol;
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (buf[m] != '\n')
		m ++;
	symbol = (char *) malloc (sizeof(char) * 4);
	while (i < 3)
	{
		symbol[i] = buf[m - 3 + i];
		i ++;
	}
	symbol[i] = 0x00;
	return (symbol);
}

char	**set(char *buf)
{
	int		*xy;
	int		**map;
	int		*max_index;
	char	**result_array;
	char	*symbol;

	symbol = symbol_check(buf);
	xy = (int *)malloc (sizeof(int) * 2);
	xy[0] = 0;
	xy[1] = 0;
	max_index = (int *) malloc (sizeof(int) * 3);
	max_index[0] = 0;
	max_index[1] = 0;
	max_index[2] = 0;
	xy = dis_array(buf, xy);
	map = ft_make_map(xy[0], xy[1], buf, symbol);
	map_init(map, xy[1], xy[0]);
	max_index = ft_max(map, xy[1], xy[0], max_index);
	map = ft_fill_square(map, max_index);
	result_array = result(map, xy, symbol);
	return (result_array);
}
