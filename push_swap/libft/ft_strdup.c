/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:24:25 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/13 10:24:26 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*d;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1);
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (0);
	while (i <= len)
	{
		d[i] = s1[i];
		i++;
	}
	return (d);
}
