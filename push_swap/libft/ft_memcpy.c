/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:19:44 by jkosiara          #+#    #+#             */
/*   Updated: 2021/01/15 18:17:06 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if ((void*)dest == '\0' && (void*)src == '\0')
		return (NULL);
	ptr = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	while (n-- > 0)
		*(ptr++) = *(ptr2++);
	return ((void*)dest);
}
