/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:12:54 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/04 19:57:15 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void ft_sort_three(t_stack *a)
{
	if (!ft_a_is_sorted(a))
	{
		if (a->i[0] < a->i[1] && a->i[0] < a->i[2])
		{
			sa(a);
			ra(a);
		}
		else if (a->i[0] > a->i[1] && a->i[0] > a->i[2])
		{
			if (a->i[1] > a->i[2])
			{
				sa(a);
				rra(a);
			}
			else
				ra(a);
		}
		else if (a->i[0] < a->i[1] && a->i[0] > a->i[2])
			rra(a);
		else
			sa(a);
	}
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	while (a->i[0] + a->i[1] != 9 && a->i[0] + a->i[1] != 3)
	{
		if (a->i[0] > a->i[1])
			ra(a);
		else
		{
			sa(a);
			ra(a);
		}
	}
	if (a->i[0] == 2 || a->i[0] == 5)
		sa(a);
	if (ft_a_is_sorted(a))
		return ;
	pb(a, b);
	pb(a, b);
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
	if (a->i[0] == 4)
	{
		ra(a);
		ra(a);
	}
}

void	ft_sort_bits(t_stack *a, t_stack *b, int bit)
{
	int	n;

	n = a->n;
	while (n-- > 0)
	{
		if ((a->i[0] >> bit) & 1)
			ra(a);
		else if (a->n > 2 && !ft_a_is_sorted(a))
			pb(a, b);
	}
	n = b->n;
	while (n-- > 0)
		pa(a, b);
}

void	ft_order_stack(t_stack *a, t_stack *b)
{
	int		bit;

	if (a->n == 2)
		ra(a);
	else if (a->n == 3)
		ft_sort_three(a);
	else
	{
		b->n = 0;
		b->i = malloc(sizeof(int) * (a->n + 1));
		if (a->n <= 5)
		{
			ft_sort_five(a, b);
			return ;
		}
		bit = 0;
		while (bit < 32 && !ft_a_is_sorted(a))
		{
			ft_sort_bits(a, b, bit);
			bit++;
		}
	}
}
