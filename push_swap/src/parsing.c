/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:16:11 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/04 20:03:52 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_read_stack(char **argv, t_stack *a)
{
	char	*s;
	char	*t;

	s = ft_strdup("");
	while (*(++argv))
	{
		t = ft_strjoin(s, *argv);
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
	if (!ft_check_stack_valid(a))
		return (0);
	ft_set_index(a);
	return (1);
}

int ft_a_is_sorted(t_stack *a)
{
	int n;

	n = a->n;
	while (n-- >1)
		if (a->i[n] < a->i[n-1])
			return (0);
	return (1);
}

int ft_check_stack_valid(t_stack *a)
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