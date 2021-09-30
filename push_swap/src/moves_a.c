/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:49:38 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/30 17:00:13 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// MOSSE DA FARE/DISPONIBILI:
// sa
// sb
// ss 
// pa 
// pb 
// ra 
// rb
// rr 
// rra 

void pa(t_stack *a, t_stack *b)
{
	int n;
	
	n = a->n;
	while (n-- > 0) //affinchè tutti gli argomenti non sono stati controllati
		a->i[n+1] = a->i[n];
	a->i[0] = b->i[0]; // pusho la prima linea di B, dentro la stack A
	a->n = 0;
	while (++n < b->n) 
		b->i[n-1] = b->i[n];
	b->n--;
	ft_putendl("pa");
}

void ra(t_stack *a)
{
	int first;
	int n;

	first = a->i[0]; //rotate su a, ruoti il primo valore in fondo 
	n = 0;
	while (++n < a->n)
		a->i[n-1] = a->i[n];
	a->i[a->n -1] = first; 
	ft_putendl("ra");
}

void rra(t_stack *a)
{
	int	last;
	int	n;

	n = a->n - 1; //reverse rotate su a, ruoti il valore dal fondo, verso l'alto
	last = a->i[n];
	while (n-- > 0)
		a->i[n + 1] = a->i[n];
	a->i[0] = last;
	ft_putendl("rra");
}

void sa(t_stack *a)
{
	int temp;

	temp = a->i[0];  //swap classico su a
	a->i[0] = a->i[1];
	a->i[1] = temp;
	ft_putendl("sa");
}