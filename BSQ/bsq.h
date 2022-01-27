/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejhong <yejhong@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:53:08 by yejhong           #+#    #+#             */
/*   Updated: 2022/01/27 11:22:34 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUF_SIZE 2000000

typedef struct s_map
{
	int		size[2];
	char	**map;
	char	symbol[3];
}t_map;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int	nb);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);

int		*dis_arraay(char *buf, int *xy);
int		**ft_make_map(int x, int y, char *buf, char *symbol);

void	map_init(int **map, int y, int x);
int		ft_three_min_compare(int **map, int i, int j);
int		*ft_max(int **map, int y, int x, int *max_index);

int		**ft_fill_square(int **map, int *max_index);
char	**set(char *buf);

int		ft_check_condition(char *line, int len);
int		ft_symbol_check(char ch, char *buf_malloc, int m);
int		ft_symbol_check2(char ch, char *buf_malloc, int m);
int		ft_put_symbols(t_map *meta_map, char *line, int len);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		is_in_symbols(char ch, char *symbols, int *not_obs);
int		ft_cnt_row(t_map *meta_map, char *file_contents);

int		ft_atoi(char *str);
char	*ft_strdup(char *src);

/*
typedef struct s_sol_finder
{
	int	max;
	int	x;
	int	y;
}t_sol;
*/

#endif
