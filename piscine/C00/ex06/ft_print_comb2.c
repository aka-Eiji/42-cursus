/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:31:22 by jkosiara          #+#    #+#             */
/*   Updated: 2020/11/30 15:13:59 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printn(int first, int second)
{
	char cipher;

	cipher = first / 10 + '0';
	write(1, &cipher, 1);
	cipher = first % 10 + '0';
	write(1, &cipher, 1);
	write(1, " ", 1);
	cipher = second / 10 + '0';
	write(1, &cipher, 1);
	cipher = second % 10 + '0';
	write(1, &cipher, 1);
}

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = 0;
	second = 1;
	while (first <= 98)
	{
		while (second <= 99)
		{
			ft_printn(first, second);
			if (!(first == 98 && second == 99))
				write(1, ", ", 2);
			second++;
		}
		first++;
		second = first + 1;
	}
}
