/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:12:54 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/30 16:59:57 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int ft_a_is_sorted(t_stack *a)
{
	int n;

	n = a->n;
	while (n-- >1)
		if (a->i[n] < a->i[n-1])
			return (0);
	return (1);
}
