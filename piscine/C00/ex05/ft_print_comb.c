/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:32:54 by jkosiara          #+#    #+#             */
/*   Updated: 2020/11/30 15:12:26 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char first;
	char second;
	char third;

	first = '0';
	second = '1';
	third = '2';
	while (first <= ('7'))
	{
		while (second <= ('8'))
		{
			while (third <= ('9'))
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				if (!(first == '7' && second == '8' && third == '9'))
					write(1, ", ", 2);
				third++;
			}
			third = ++second + 1;
		}
		second = ++first;
	}
}
