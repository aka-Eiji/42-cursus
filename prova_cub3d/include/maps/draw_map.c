/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:43:42 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/18 16:42:07 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    my_pixel_put(t_vars *vars, t_maps *maps, int i, int j)
{
    int     x;
    int     y;

    y = 0;
    while (y < CELL_SIZE)
    {
        x = 0;
        while (x < CELL_SIZE)
        {
            if (maps->mtx[j][i] == '1')
                mlx_pixel_put(vars->mlx, vars->win, ((i * CELL_SIZE) + y), ((j * CELL_SIZE) + x), 0x00FFD1DC);
            else if (maps->mtx[j][i] == '0')
                mlx_pixel_put(vars->mlx, vars->win, ((i * CELL_SIZE) + y), ((j * CELL_SIZE) + x), 0x00FFFFFF);
            x++;
        }
        y++;
    }
}

void    ft_draw_map(t_vars *vars, t_maps *maps)
{
    int     i;
    int     j;

    i = 0;
    while (i < maps->mapy)
    {
        j = 0;
        while (j < ft_strlen(maps->mtx[i]))
        {
            my_pixel_put(vars, maps, j, i);
            j++;
        }
        i++;
    }
}

t_pos	ft_pos(t_maps *maps)
{
	char	c;
	int		i;
	int		j;
	t_pos	pos;

	i = -1;
	pos.posX = 0;
	pos.posY = 0;
	pos.dirX = 0;
	pos.dirY = 0;
	while (++i < maps->mapy)
	{
		j = -1;
		while (++j < maps->mapx)
		{
			c = maps->mtx[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				pos.posX = (double)j + 0.5;
				pos.posY = (double)i + 0.5;
				pos.dirX = (c == 'E') || (c == 'W') ? 1 : 0;
				pos.dirX *= (c == 'W') ? -1 : 1;
				pos.dirY = (c == 'S') || (c == 'N') ? 1 : 0;
				pos.dirY *= (c == 'N') ? -1 : 1;
			}
		}
	}
	return (pos);
}