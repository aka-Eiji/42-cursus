/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:41:29 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/21 15:09:16 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void ft_print_stack(t_numlist *a)
{
	t_numlist *temp;
	
	temp = a; 
	if(!temp)
	{	
		write(1, "list NULL, error.", 18);
		exit(1);
	}
	while(a)
	{
		ft_putnbr(temp->content);
		temp = temp->next;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

int ft_count_list(t_numlist *a)
{
	t_numlist *temp;
	int size;

	size = 0;

	temp = a;
	while ( a && a->next != 0)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int ft_cycle_list(t_numlist *lst)
{
	int min = -2147483648;

	while(lst->next != 0)
	{
		if (lst->content > min)
			min = lst->content;
			lst->next; 	
	}
}
