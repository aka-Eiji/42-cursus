/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:05:51 by jkosiara          #+#    #+#             */
/*   Updated: 2021/12/07 15:05:52 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	ft_nbrsize(long n)
{
	unsigned int	size;

	size = 1;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(long n)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_nbrsize(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > i)
	{
		size--;
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_isnumb(char *num)
{
	int	i;

	i = 0;
	if (num[i] != '\0')
	{
		while (num[i])
		{
			if (num[i] == '+' || num[i] == '-')
				i++;
			else
				break ;
		}
		while (num[i])
		{
			if (num[i] >= '0' && num[i] <= '9')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
