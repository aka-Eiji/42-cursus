/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:49:38 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/21 16:02:09 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int ft_a_is_sorted(t_numlist *a)
{
	t_numlist *temp;

	temp = a;
	while ( a && a->next != 0)
	{
		if ( a->next->content < a->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_sort(t_numlist **a, t_numlist **b, int size)
{
	int	i;
	int j;
	int max_num; 
	int max_bytes;
	t_numlist	*current;
	
	i = 0;
	max_bytes = 0;
	max_num = ft_cycle_list(a);
	while ((max_num >> max_bytes) != 0)
		max_bytes++;
	while (i < max_bytes)
	{
		j = 0;
		while (j++ < size)
		{
			current = *a;
			if ((((current->content >> i)&1) == 1))
				ft_ra(a, 1);
			else
				ft_push_to(a, b, 2);
		}
		while (*b)
			ft_push_to(b, a, 1);
		i++;
	}
}