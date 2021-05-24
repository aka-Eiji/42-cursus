/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:44:38 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/24 17:02:05 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	ft_init_player(t_player *player)
{
	player->rot_angle = M_PI_2;
	player->planeX = 0;
	player->planeY = 0.66;
	player->raydirX = 0;
	player->raydirY = 0;
	player->posX = 0;
	player->posY = 0;
	player->dirX = 0;
	player->dirY = 0;
	player->b_mapX = player->posX;
	player->b_mapY = player->posY;
	player->mov_speed = 3.0;
	player->side_distX = fabs(1 / player->raydirX);
	player->side_distY = fabs(1 / player->raydirY);
	player->hit = 0;
	player->pix = 0;
	player->width = 0;
	player->cameraX = (2 * player->pix) /  (double)player->width - 1;
	player->raydirX = player->dirX + player->planeX * player->cameraX;
	player->raydirY = player->dirY + player->planeY * player->cameraX;
	player->stepX = 0;
	player->stepY = 0;

}

void		next_step(t_all *all)
{
	if (all->player.raydirX < 0)
	{
		all->player.stepX = -1;
		all->player.side_distX = (all->player.posX - all->maps.mapx) * all->player.delta_distX;
	}
	else
	{
		all->player.stepX = 1;
		all->player.side_distX = (all->maps.mapx + 1.0 - all->player.posX) * all->player.delta_distX;
	}
	if (all->player.raydirY < 0)
	{
		all->player.stepY = -1;
		all->player.side_distY = (all->player.posY - all->maps.mapy) * all->player.delta_distY;
	}
	else
	{
		all->player.stepY = 1;
		all->player.side_distY = (all->maps.mapy + 1.0 - all->player.posY) * all->player.delta_distY;
	}
}