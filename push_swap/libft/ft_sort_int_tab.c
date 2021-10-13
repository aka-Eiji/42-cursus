/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:24:17 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/13 10:24:19 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *new, int *old)
{
	int	temp;

	temp = *new;
	*new = *old;
	*old = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}
