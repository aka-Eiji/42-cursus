/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:18:16 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/21 15:08:16 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	t_numlist *a;
	t_numlist *b;
	int size; 

	size = 0;
	if (argc == 0)
		write(1, "No arguments, retry.", 20);
	ft_put_in_list(a, argv);
	if (ft_a_is_sorted(a) == 1) //controllo se è ordinato, se è ordinato libero la memoria e termino il programma (aggiungere avviso in stampa)
		free(a);
		return(0);
	size = ft_count_list(a);
	ft_sort(&a, &b, size);
	ft_print_stack(a);
}
