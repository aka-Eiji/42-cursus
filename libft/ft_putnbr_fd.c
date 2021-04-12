/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:56:51 by jkosiara          #+#    #+#             */
/*   Updated: 2021/01/27 16:57:03 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long int		long_n;

	if (n < 0)
	{
		long_n = -(long int)n;
		write(fd, "-", 1);
	}
	else
		long_n = n;
	if (long_n > 9)
	{
		ft_putnbr_fd(long_n / 10, fd);
		ft_putchar_fd((long_n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(long_n + '0', fd);
}
