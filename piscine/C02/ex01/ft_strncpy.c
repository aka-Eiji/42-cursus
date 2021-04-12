/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:45:10 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/04 14:03:05 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (src[i] == 0)
		{
			while (i < n)
			{
				dest[i] = 0;
				i++;
			}
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
