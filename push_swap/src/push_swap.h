/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:43:30 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/04 19:07:07 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
typedef struct s_stack
{
	int n;
	int *arr;
	int *i;
}			t_stack;

int check_stat_valid(t_stack *a);
int read_stack(char **argv, t_stack*a);
int ft_a_is_sorted(t_stack *a);

/* moves on b stack: */
void pb(t_stack *a, t_stack *b);
void rb(t_stack *b);
void rrb(t_stack *b);
void sb(t_stack *b);

/* moves on a stack: */
void pa(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rra(t_stack *a);
void sa(t_stack *a);

/* utils: */
int		ft_isspace(int c);
int		ft_d_count(char *s);
int		ft_split_atoi(char *s, t_stack *a);
void	ft_free_stack(t_stack*a, t_stack *b);
void	ft_putendl(char *s);
void	ft_sort_index(t_stack *stack);
void	set_index(t_stack *a);


#endif