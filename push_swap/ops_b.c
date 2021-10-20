/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:39:47 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/12 18:39:48 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	int	n;

	n = b->n;
	while (n-- > 0)
		b->i[n + 1] = b->i[n];
	b->i[0] = a->i[0];
	b->n++;
	n = 0;
	while (++n < a->n)
		a->i[n - 1] = a->i[n];
	a->n--;
	ft_putendl("pb");
}

void	rb(t_stack *b)
{
	int	first;
	int	n;

	first = b->i[0];
	n = 0;
	while (++n < b->n)
		b->i[n - 1] = b->i[n];
	b->i[b->n - 1] = first;
	ft_putendl("rb");
}

void	rrb(t_stack *b)
{
	int	last;
	int	n;

	n = b->n - 1;
	last = b->i[n];
	while (n-- > 0)
		b->i[n + 1] = b->i[n];
	b->i[0] = last;
	ft_putendl("rrb");
}

void	sb(t_stack *b)
{
	int	t;

	t = b->i[0];
	b->i[0] = b->i[1];
	b->i[1] = t;
	ft_putendl("sb");
}
