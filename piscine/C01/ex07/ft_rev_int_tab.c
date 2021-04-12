/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:23:11 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/03 15:27:54 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int counter;
	int box;

	counter = 0;
	while (counter < size / 2)
	{
		box = tab[counter];
		tab[counter] = tab[size - 1 - counter];
		tab[size - 1 - counter] = box;
		counter++;
	}
}
