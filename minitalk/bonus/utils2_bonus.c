/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:17:29 by jkosiara          #+#    #+#             */
/*   Updated: 2021/06/14 19:05:25 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == 32)
		return (1);
	if (c == 9)
		return (1);
	if (c == 10)
		return (1);
	if (c == 11)
		return (1);
	if (c == 12)
		return (1);
	if (c == 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		negative;

	i = 0;
	num = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (int)str[i] - 48;
		i++;
	}
	return (num * negative);
}

void	ft_string_complement(char *string)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (string[i] != 0)
	{
		if (string[i] == '0')
			string[i] = '1';
		else if (string[i] == '1')
			string[i] = '0';
		i++;
	}
	i = 7;
	while (i > 0 && flag != 1)
	{
		if (string[i] == '0')
		{
			string[i] = '1';
			flag = 1;
		}
		else
			string[i] = '0';
		i--;
	}
}

