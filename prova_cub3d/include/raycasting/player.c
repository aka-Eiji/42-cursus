/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:44:38 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/26 14:24:10 by mmurello         ###   ########.fr       */
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
	player->cameraX = (2 * player->pix) /  (double)player->width - 1;
	player->raydirX = player->dirX + player->planeX * player->cameraX;
	player->raydirY = player->dirY + player->planeY * player->cameraX;
	player->turn_direction = 0;
	player->turn_speed = 45 * (M_PI / 180);
	player->px = player->posX + cos(player->rot_angle) * 40;
	player->py = player->posY + sin(player->rot_angle) * 40;
}