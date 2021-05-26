/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:43:42 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/26 16:00:49 by mmurello         ###   ########.fr       */
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

void    ft_draw_line(t_all *all)
{
    all->player.px = all->player.posX + cos(all->player.rot_angle) * 40;
    all->player.py = all->player.posY + sin(all->player.rot_angle) * 40;

    int i;
    int j;

    i = 0;
    while (i < 1)
    {
        j = 0;
        while (j < all->player.px)
        {
            mlx_pixel_put(all->vars.mlx, all->vars.win, (all->player.posX * CELL_SIZE)+ j, (all->player.posY * CELL_SIZE) + i, 0x00FF3300);
            j++;
        }
        i++;
    }
}

void    ft_draw_player(t_all *all)
{
    double i = 5;
    double j;

    while (i > -5)
    {
        j = -5;
        while (j < 5)
        {
            mlx_pixel_put(all->vars.mlx, all->vars.win, (all->player.posX * CELL_SIZE + j), (all->player.posY * CELL_SIZE + i), 0x000033FF);
            j++;
        }
        i--;
    }
}

void    ft_move_player(t_all *all)
{
    all->player.rot_angle += all->player.turn_direction * all->player.turn_speed;
    
    double move_step;
    double new_posX;
    double new_posY;

    move_step = all->player.walk_direction * SPEED;
    new_posX = all->player.posX + cos(all->player.rot_angle) * move_step;
    new_posY = all->player.posY + sin(all->player.rot_angle) * move_step;
    all->player.posX = new_posX;
    all->player.posY = new_posY;
}

void    ft_init_keys(t_all *all)
{
    all->keys.up = 0;
    all->keys.down = 0;
    all->keys.left = 0;
    all->keys.right = 0;
    all->keys.cam_left = 0;
    all->keys.cam_right = 0;
}

void    ft_keys(t_all *all)
{
    if (all->keys.up == 1)
    {
        all->player.walk_direction += 1;
        all->player.posY += 1;

    }
    else if (all->keys.down == 1)
    {
        all->player.walk_direction -= 1;
        all->player.posY -= 1;
    }
    else if (all->keys.left == 1)
    {
        all->player.walk_direction -= 1;
        all->player.posX -= 1;
    }
    else if (all->keys.right == 1)
    {
        all->player.walk_direction += 1;
        all->player.posX += 1;
    }
}

