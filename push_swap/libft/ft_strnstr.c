/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:06:40 by jkosiara          #+#    #+#             */
/*   Updated: 2021/01/29 17:35:51 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < l)
	{
		while ((haystack[i] == needle[j] || needle[j] == '\0') && i < l)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		i++;
	}
	return (NULL);
}
