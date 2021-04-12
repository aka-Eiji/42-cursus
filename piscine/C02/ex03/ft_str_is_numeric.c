/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:36:37 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/05 18:36:39 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int		ft_str_is_numeric(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (str[i] != 0)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			flag = 0;
		}
		i++;
	}
	return (flag);
}
