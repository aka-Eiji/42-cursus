/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:57:17 by jkosiara          #+#    #+#             */
/*   Updated: 2021/01/28 12:59:40 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*done;
	unsigned int	i;

	if (!s || !(done = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		done[i] = f(i, s[i]);
		i++;
	}
	done[i] = 0;
	return (done);
}
