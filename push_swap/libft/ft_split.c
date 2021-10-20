/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:24:21 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/13 10:24:23 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wcount(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	char	*start;
	size_t	i;

	d = (char **)malloc((ft_wcount(s, c) + 1) * sizeof(char *));
	if (!s || !d)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			d[i] = (char *)malloc(s - start + 1);
			if (!d[i])
				return (0);
			ft_strlcpy(d[i++], start, (s - start + 1));
		}
		else
			s++;
	}
	d[i] = 0;
	return (d);
}
