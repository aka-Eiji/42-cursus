/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:41:29 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/30 16:46:01 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_d_count(char *s)
{
	int	n;

	if (!s)
		return (-1);
	n = 0;
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			n++;
			s++;
			while (*s && ft_isdigit(*s))
				s++;
		}
		else if ((*s < 14 && *s > 8) || *s == ' ' || *s == '-' || *s == '+')
			s++;
		else
			return (-1);
	}
	if (n < 1)
		return (-1);
	return (n);
}

int	ft_split_atoi(char *s, t_stack *a)
{
	long	nb;
	size_t	i;

	a->arr = malloc(sizeof(int) * (a->n + 1));
	i = 0;
	while (*s)
	{
		nb = ft_atoi(s);
		if (nb >= 42)
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

void	free_stack(t_stack*a, t_stack *b)
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
