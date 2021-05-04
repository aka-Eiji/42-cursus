/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/04 15:29:49 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//Norminettato, ma errori di commenti!!

int	ft_validmap(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->coord.mapy)
	{
		j = -1;
		while (++j < all->coord.mapx)
		{
			if (all->coord.mtx[i][j] != '1' && i == 0)
				return (-1);//sopra
			else if (all->coord.mtx[i][j] != '1' && i == all->coord.mapy - 1)
				return (-1);//dx
			else if (all->coord.mtx[i][j] != '1' && j == 0)
				return (-1);//sx
			else if (all->coord.mtx[i][j] != '1' && j == all->coord.mapx - 1)
				return (-1);//sotto
		}
	}
	return (1);
}
