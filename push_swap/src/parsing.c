/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:16:11 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/04 17:16:17 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int read_stack(char **argv, t_stack*a)
{
	char *str;
	char *temp;
	
	str = ft_strdup("");
	while (*(++argv))
	{
		temp = ft_strjoin(str, *argv);
		free(str);
		str = temp;
		temp = ft_strjoin (str, " ");
		free(str);
		str = temp;
	}
	a->n = ft_d_count(str);
	if (a->n <1 || !ft_split_atoi(str, a))
	{
		free(temp);
		return (0);
	}
	free(temp);
	if(!check_stack_valid(a))
		return(0);
	set_index(a);
	return (-1);

}

int check_stat_valid(t_stack *a)
{
	int n;
	int i;
	int j;
	int nb;

	if (a->n == 1 && a->arr[0] == 0)
		return(-1);
	n = a->n;
	j = 1;
	while (n-- > 0)
	{
		nb = a->arr[j - 1];
		i = j;
		while (nb != a->arr[i] && n-- > 1)
			i++;
		if (nb != a->arr[i] && i != 0)
			return (0);
		j++;
		n = a->n - j;
	}
	return (1);
}