/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:19:39 by myson             #+#    #+#             */
/*   Updated: 2022/01/15 08:27:46 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	while (dest[i] != 0x00)
	{
		i++;
	}
	n = i;
	i = 0;
	while (i < nb && src[i] != 0x00)
	{
		dest[i + n] = src[i];
		i++;
	}
	dest[i + n] = 0x00;
	return (dest);
}
