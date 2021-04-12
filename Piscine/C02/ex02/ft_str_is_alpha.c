/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:03:37 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/04 14:11:14 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int		ft_str_is_alpha(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (str[i] != 0)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!(str[i] >= 'A' && str[i] <= 'Z'))
				flag = 0;
		}
		i++;
	}
	return (flag);
}
