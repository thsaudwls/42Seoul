/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:24:09 by myson             #+#    #+#             */
/*   Updated: 2022/01/11 08:24:31 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_while(char *dest, char *src)
{
	while (*src != 0x00)
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	*dest = 0x00;
}

char	*ft_strcpy(char *dest, char *src)
{
	ft_while(dest, src);
	return (dest);
}
