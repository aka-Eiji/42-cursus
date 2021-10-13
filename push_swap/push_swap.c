/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:39:55 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/13 11:49:37 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_ordered(t_stack *a)
{
	int	n;

	n = a->n;
	while (n-- > 1)
		if (a->i[n] < a->i[n - 1])
			return (0);
	return (1);
}

int	check_stack_valid(t_stack *a)
{
	int	n;
	int	i;
	int	j;
	int	nb;

	if (a->n == 1 && a->arr[0] == 0)
		return (1);
	n = a->n;
	j = 1;
	while (n-- > 0)
	{
		nb = a->arr[j - 1];
		i = j;
		while (nb != a->arr[i] && n-- > 1)
			i++;
		if (nb == a->arr[i] && i != 0)
			return (0);
		j++;
		n = a->n - j;
	}
	return (1);
}

int	read_stack(char **av, t_stack *a)
{
	char	*s;
	char	*t;

	s = ft_strdup("");
	while (*(++av))
	{
		t = ft_strjoin(s, *av);
		free(s);
		s = t;
		t = ft_strjoin(s, " ");
		free(s);
		s = t;
	}
	a->n = ft_d_count(s);
	if (a->n < 1 || !ft_split_atoi(s, a))
	{
		free(t);
		return (0);
	}
	free(t);
	if (!check_stack_valid(a))
		return (0);
	set_index(a);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (-1);
	else if (!read_stack(av, &a))
	{
		ft_putendl("Error, insert only numbers!");
		free_stacks(&a, &b);
		return (-1);
	}
	else if (check_stack_ordered(&a))
	{
		free_stacks(&a, &b);
		return (0);
	}
	else
		order_stack(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
