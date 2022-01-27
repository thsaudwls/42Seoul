/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:51:39 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/23 21:11:21 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	check_str_valid(char *str)
{	
	if (ft_strlen(str) >= 3)
	{
		if (str[0] == '0' && str[1] == '0' && str[2] == '0')
		{	
			return (1);
		}
	}
	return (0);
}

int	check_input_num(int argc, char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[argc - 1][i] != '\0')
	{
		if (argv[argc - 1][i] >= '0' && argv[argc - 1][i] <= '9')
			count++;
		i++;
	}
	if (count == i)
		return (1);
	return (0);
}

void	check_many_zero(int argc, char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[argc - 1][i] != '\0')
	{
		if (argv[argc - 1][i] == '0')
			count++;
		i++;
	}
	if (count == i)
		argv[argc - 1][1] = '\0';
}
