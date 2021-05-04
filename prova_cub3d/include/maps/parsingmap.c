/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/04 14:19:27 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_validmap(t_all *all)
{
	int i;
	int j;

	i = -1;
	while(++i < all->coord.mapy)
	{
		j = -1;
		while(++j < all->coord.mapx)
		{
			if (all->coord.mtx[i][j] != '1' && i == 0) // sopra
				return (-1);
			else if (all->coord.mtx[i][j] != '1' && i == all->coord.mapy - 1) // dx
				return (-1);
			else if (all->coord.mtx[i][j] != '1' && j == 0) // sx
				return (-1);
			else if (all->coord.mtx[i][j] != '1' && j == all->coord.mapx - 1) // sotto
				return (-1);
		}
	}
	return (1);
}
