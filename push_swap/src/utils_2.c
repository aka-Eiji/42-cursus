/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:13:15 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/04 19:03:05 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_sort_index(t_stack *stack)
{
	int i;
	int j;
	int *temp;
	int n;

	n = stack->n;
	temp = malloc(sizeof(int) * (n + 1));
	while (n-- > 0)
		temp[n] = stack->arr[n];
	i = 0;
	while (i < stack->n - 1)
	{
		j = 0;
		while (j < stack->n - 1 - i)
		{
			if (temp[j] > temp[j + 1])
			{
				ft_swap(&temp[j], &temp[j + 1]);
				ft_swap(&stack->i[j], &stack->i[j + 1]);
			}
			j++;
		}
		i++;
	}
	free(temp);
}

void	set_index(t_stack *a)
{
	int	n;
	int	*index;

	n = a->n;
	a->i = malloc(sizeof(int) * (n + 1));
	index = malloc(sizeof(int) * (n + 1));
	while (n-- > 0)
		a->i[n] = n + 1;
	ft_sort_index_stack(a);
	while (n++ < a->n)
		index[n] = a->i[n];
	n = 0;
	while (n < a->n)
	{
		a->i[index[n] - 1] = n + 1;
		n++;
	}
	free(index);
}