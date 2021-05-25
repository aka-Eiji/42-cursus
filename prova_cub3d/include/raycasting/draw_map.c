/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:43:42 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/25 15:13:36 by mmurello         ###   ########.fr       */
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
            else if (maps->mtx[j][i] == 'N' || maps->mtx[j][i] == 'S' || maps->mtx[j][i] == 'W'
                    || maps->mtx[j][i] == 'E')
                    mlx_pixel_put(vars->mlx, vars->win, ((i * CELL_SIZE) + y), ((j * CELL_SIZE) + x), 0x00AD099D);
            // else if (maps->mtx[j][i] == '2')
            //     mlx_pixel_put(vars->mlx, vars->win, ((i * CELL_SIZE) + y), ((j * CELL_SIZE) + x), 0x00FFFB7D);
            x++;
        }
        y++;
    }
}

int    ft_draw_map(t_vars *vars, t_maps *maps)
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
    return (0);
}


void	ft_pos(t_maps *maps, t_player *player)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (++i < maps->mapy)
	{
		j = -1;
		while (++j < maps->mapx)
		{
			c = maps->mtx[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				player->posX = (double)j + 0.5;                     // centra il personaggio
				player->posY = (double)i + 0.5;
				player->dirX = (c == 'E') || (c == 'W') ? 1 : 0;    //cambiare ternario per norminette -.-
				player->dirX *= (c == 'W') ? -1 : 1;
				player->dirY = (c == 'S') || (c == 'N') ? 1 : 0;
				player->dirY *= (c == 'N') ? -1 : 1;
			}
		}
	}
}