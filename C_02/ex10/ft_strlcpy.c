/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:21:07 by myson             #+#    #+#             */
/*   Updated: 2022/01/11 16:25:54 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *src)
{
	unsigned int	i;

	i = 0;
	while (*src != 0x00)
	{
		i ++;
		src ++;
	}
	return (i);
}

void	ft_next(char *dest, char *src, unsigned int i, unsigned int len)
{
	while (i < len)
	{
		*dest = *src;
		dest ++;
		src ++;
		i ++;
	}
	*dest = 0x00;
}

void	ft_while(char *dest, char *src, unsigned int i, unsigned int size)
{
	while (i + 1 < size)
	{
		*dest = *src;
		dest ++;
		src ++;
		i ++;
	}
	*dest = 0x00;
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_len(src);
	i = 0;
	if (len < size)
	{
		ft_next(dest, src, i, len);
	}
	else if (size == 0)
		return (len);
	else
		ft_while(dest, src, i, size);
	return (len);
}
