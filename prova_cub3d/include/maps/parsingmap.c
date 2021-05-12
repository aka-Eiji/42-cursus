/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/12 17:39:42 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void ft_init(t_maps *maps)
{	
	maps->mapx = 0;
	maps->mapy = 0;
	maps->mtx = NULL;
}

int		ft_jumpspace(char *newline, int i)
{
	while ((newline[i] == ' ' || newline[i] == '\t' || newline[i] == '\n')
	|| (newline[i] == '\r' || newline[i] == '\v' || newline[i] == '\f'))
		(i)++;
	return (i);
}

int ft_count_y(t_maps *maps, char *newline)
{
	int i;

	i = 0;
	if (newline[0] != '1')
	{
		i = ft_jumpspace(newline, i);
		if (newline[i] == '1')
		{
			maps->mapy++;
			newline++;
		}
	}
	else if (newline[0] == '1')
	{
		maps->mapy++;
		newline++;
	}
		return (maps->mapy);
}

int	ft_validmap(t_maps *maps, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->WINDOW_HEIGHT)
	{
		j = 0;
		while (j < all->WINDOW_WIDTH)
		{
			if (maps->mtx[i][j] != '1' && i == 0)
				return (-1);
			else if (maps->mtx[i][j] != '1' && i == (all->WINDOW_HEIGHT - 1))
				return (-1);
			else if (maps->mtx[i][j] != '1' && j == 0)
				return (-1);
			else if (maps->mtx[i][j] != '1' && j == (all->WINDOW_WIDTH - 1))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}