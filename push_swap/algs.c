/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:40:19 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/12 18:40:20 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (!check_stack_ordered(a))
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

void	sort_five(t_stack *a, t_stack *b)
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
	if (check_stack_ordered(a))
		return ;
	pb(a, b);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if (a->i[0] == 4)
	{
		ra(a);
		ra(a);
	}
}

void	sort_bits(t_stack *a, t_stack *b, int bit)
{
	int	n;

	n = a->n;
	while (n-- > 0)
	{
		if ((a->i[0] >> bit) & 1)
			ra(a);
		else if (a->n > 2 && !check_stack_ordered(a))
			pb(a, b);
	}
	n = b->n;
	while (n-- > 0)
		pa(a, b);
}

void	order_stack(t_stack *a, t_stack *b)
{
	int		bit;

	if (a->n == 2)
		ra(a);
	else if (a->n == 3)
		sort_three(a);
	else
	{
		b->n = 0;
		b->i = malloc(sizeof(int) * (a->n + 1));
		if (a->n <= 5)
		{
			sort_five(a, b);
			return ;
		}
		bit = 0;
		while (bit < 32 && !check_stack_ordered(a))
		{
			sort_bits(a, b, bit);
			bit++;
		}
	}
}
