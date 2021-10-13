/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:40:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/12 18:40:10 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_atoi(char *s, t_stack *a)
{
	long	nb;
	size_t	i;

	a->arr = malloc(sizeof(int) * (a->n + 1));
	i = 0;
	while (*s)
	{
		nb = ft_atoi(s);
		if (nb >= 3000000000)
			return (0);
		else
			a->arr[i++] = nb;
		while (*s && !ft_isdigit(*s))
			s++;
		while (*s && ft_isdigit(*s))
			s++;
	}
	return (1);
}

void	ft_sort_index_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	*tmp;
	int	n;

	n = stack->n;
	tmp = malloc(sizeof(int) * (n + 1));
	while (n-- > 0)
		tmp[n] = stack->arr[n];
	i = 0;
	while (i < stack->n - 1)
	{
		j = 0;
		while (j < stack->n - 1 - i)
		{
			if (tmp[j] > tmp[j + 1])
			{
				ft_swap(&tmp[j], &tmp[j + 1]);
				ft_swap(&stack->i[j], &stack->i[j + 1]);
			}
			j++;
		}
		i++;
	}
	free(tmp);
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

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->i && b->i)
	{
		free(a->i);
		free(a->arr);
		a->n = 0;
		free(b->i);
		b->n = 0;
	}
	else
	{
		if (a->i)
			free(a->i);
		free(a->arr);
		a->n = 0;
	}
}
