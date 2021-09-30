/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:18:16 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/30 16:59:44 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	int size; 

	size = 0;
	if (argc <= -1)
	{
		write(1, "No arguments, retry.", 20);
		return (-1);
	}
	else if (!read_stack(argv, &a))
	{
		ft_putendl("Error");
		free_stack(&a,&b);
		return (-1);
	}
}