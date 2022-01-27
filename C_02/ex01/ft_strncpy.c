/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:27:37 by myson             #+#    #+#             */
/*   Updated: 2022/01/10 18:27:52 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *src)
{
	int	i;

	i = 0;
	while (*src != 0x00)
	{
		i ++;
		src ++;
	}
	return (i);
}

void	next1(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src != 0x00)
	{
		*dest = *src;
		dest ++;
		src ++;
		i++;
	}
	while (i < n)
	{
		*dest = 0x00;
		dest ++;
		i++;
	}
}

void	next2(char *dest, char *src, unsigned int i, unsigned int n)
{
	while (++i <= n)
	{
		*dest = *src;
		dest ++;
		src ++;
	}
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_len(src);
	i = 0;
	if (len < n)
	{
		next1(dest, src, n);
	}
	else
		next2(dest, src, i, n);
	return (dest);
}
