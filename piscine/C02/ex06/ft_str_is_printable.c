/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:36:06 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/05 18:36:07 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int		ft_str_is_printable(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (str[i] != 0)
	{
		if (str[i] < 32)
		{
			flag = 0;
		}
		else if (str[i] >= 127)
		{
			flag = 0;
		}
		i++;
	}
	return (flag);
}
