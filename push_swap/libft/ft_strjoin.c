/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:23:47 by jkosiara          #+#    #+#             */
/*   Updated: 2021/02/01 16:07:25 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*joinstatus(char const *str1, char const *str2)
{
	char	*newstring;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(str1);
	len_s2 = ft_strlen(str2);
	newstring = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		newstring[i] = str1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		newstring[i] = str2[i - len_s1];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	joined = joinstatus(s1, s2);
	return (joined);
}
