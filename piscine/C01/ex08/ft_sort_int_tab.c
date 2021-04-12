/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:52:21 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/03 16:00:00 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int counter;
	int countermin;
	int box;

	counter = 0;
	while (counter < size - 1)
	{
		countermin = 0;
		while (countermin < size - 1)
		{
			if (tab[countermin] > tab[countermin + 1])
			{
				box = tab[countermin + 1];
				tab[countermin + 1] = tab[countermin];
				tab[countermin] = box;
			}
			countermin++;
		}
		counter++;
	}
}
