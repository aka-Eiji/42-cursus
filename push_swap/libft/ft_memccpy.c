/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:45:19 by jkosiara          #+#    #+#             */
/*   Updated: 2021/01/19 17:17:50 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		if (ptr2[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}
