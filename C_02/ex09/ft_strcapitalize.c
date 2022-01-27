/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:47:18 by myson             #+#    #+#             */
/*   Updated: 2022/01/11 13:47:24 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pass(char *str)
{
	int	i;

	i = 0;
	if (*str >= 1 && *str <= 47)
		i = 1;
	else if (*str >= 58 && *str <= 64)
		i = 1;
	else if (*str >= 91 && *str <= 96)
		i = 1;
	else if (*str >= 123)
		i = 1;
	return (i);
}

void	ft_algo(char *str, int i)
{
	while (*str != 0x00)
	{
		i = ft_pass(str);
		while (i == 1)
		{
			str ++;
			i = ft_pass(str);
		}
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str ++;
		if (*str == 0x00)
			break ;
		i = ft_pass(str);
		while (i == 0 && *str != 0x00)
		{
			if (*str >= 'A' && *str <= 'Z')
				*str += 32;
			i = ft_pass(str);
			str ++;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_algo(str, i);
	return (str);
}
