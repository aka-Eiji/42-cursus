/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:18:16 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/12 17:46:57 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (-1);
	else if (!ft_read_stack(argv, &a))
	{
		ft_putendl("Error");
		ft_free_stack(&a, &b);
		return (-1);
	}
	else if (ft_a_is_sorted(&a))
	{
		ft_free_stack(&a, &b);
		return (0);
	}
	else
		ft_order_stack(&a, &b);
	ft_free_stack(&a, &b);
	return (0);
}