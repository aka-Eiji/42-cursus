/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:05:28 by jkosiara          #+#    #+#             */
/*   Updated: 2021/02/01 16:10:07 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nlen(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int				len;
	char			*str;
	int				sign;
	unsigned int	nb;

	sign = 1;
	if (n < 0)
	{
		nb = -n;
		sign = 0;
		len = nlen(nb) + 1;
	}
	else
		nb = n;
	if (n >= 0)
		len = nlen(nb);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	str[len] = 0;
	if (!sign)
		str[0] = '-';
	str[--len] = '0' + (nb % 10);
	while (nb /= 10)
		str[--len] = '0' + (nb % 10);
	return (str);
}
