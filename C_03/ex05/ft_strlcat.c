/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:38:16 by myson             #+#    #+#             */
/*   Updated: 2022/01/17 18:11:10 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *c)
{
	unsigned int	i;

	i = 0;
	while (c[i] != 0x00)
		i ++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	len_dest = ft_len(dest);
	len_src = ft_len(src);
	if (size == 0)
		return (len_src);
	if (size <= len_dest)
		return (len_src + size);
	while (src[i] != 0x00 && len_dest + i + 1 < size)
	{
		dest[len_dest + i] = src[i];
		i ++;
	}
	dest[len_dest + i] = 0x00;
	if (size > len_dest)
		return (len_dest + len_src);
	return (0);
}
