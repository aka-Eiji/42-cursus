/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:49:24 by jkosiara          #+#    #+#             */
/*   Updated: 2021/01/29 17:39:57 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*returnvalue;
	int		i;

	returnvalue = 0;
	i = ft_strlen(s);
	while (i >= 0 && s[i] >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			returnvalue = &((char*)s)[i];
			break ;
		}
		i--;
	}
	return (returnvalue);
}
