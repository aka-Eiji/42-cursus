/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:47:49 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/04 17:06:02 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void pb(t_stack *a, t_stack *b)
{
	int n;
	
	n = b->n;
	while (n-- > 0) //affinchè tutti gli argomenti non sono stati controllati
		b->i[n+1] = b->i[n];
	b->i[0] = a->i[0]; // pusho la prima linea di A, dentro la stack B
	b->n = 0;
	while (++n < a->n) 
		a->i[n-1] = a->i[n];
	a->n--;
	ft_putendl("pa");
}

void rb(t_stack *b)
{
	int first;
	int n;

	first = b->i[0]; //rotate su b, ruoti il primo valore in fondo 
	n = 0;
	while (++n < b->n)
		b->i[n-1] = b->i[n];
	b->i[b->n -1] = first; 
	ft_putendl("ra");
}

void rrb(t_stack *b)
{
	int	last;
	int	n;

	n = b->n - 1; //reverse rotate su b, ruoti il valore dal fondo, verso l'alto
	last = b->i[n];
	while (n-- > 0)
		b->i[n + 1] = b->i[n];
	b->i[0] = last;
	ft_putendl("rrb");
}

void sb(t_stack *b)
{
	int temp;

	temp = b->i[0];  //swap classico su b
	b->i[0] = b->i[1];
	b->i[1] = temp;
	ft_putendl("sb");
}