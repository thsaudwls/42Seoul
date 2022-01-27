/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejhong <yejhong@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:09:48 by yejhong           #+#    #+#             */
/*   Updated: 2022/01/26 20:26:59 by yejhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	value;

	value = 0;
	while (*str && *str == '0')
		str++;
	while (*str)
		value = (value * 10) + *(str++) - '0';
	return (value);
}
