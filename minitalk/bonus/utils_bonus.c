/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:17:38 by jkosiara          #+#    #+#             */
/*   Updated: 2021/06/16 17:35:39 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	nlen(int n)
{
	if (n < 0)
	{
		if (n > -10 && n < 0)
			return (2);
		else
			return (nlen(n / 10 * (-1)) + 2);
	}
	if (n < 10)
		return (1);
	return (nlen(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;

	i = nlen(n);
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	dst[i--] = 0;
	if (n < 0)
	{
		dst[0] = 45;
		dst[i] = (n % 10) * (-1) + 48;
		n = (n / 10) * (-1);
		if (n == 0)
			return (dst);
		i--;
	}
	while ((n / 10) > 0)
	{
		dst[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	dst[i] = n + 48;
	return (dst);
}

int ft_count_bytes(char s)
{
	int i;

	i = 0;
	while (s < 0)
	{
		s = s << 1;
		i++;
	}
	return (i);
}

void	ft_putchar_fd(char *c, int fd, int byte)
{
	write(fd, c, byte);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int byte;
	
	i = 0;
	if (fd != 0 && s != 0)
	{
		while (s[i])
		{
			if (s[i] < 0)
			{
				byte = ft_count_bytes(s[i]);
			}
			else 
				byte = 1;
			ft_putchar_fd(&s[i], fd, byte);
			i += byte;
		}
	}
}