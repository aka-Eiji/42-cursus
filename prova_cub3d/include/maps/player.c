/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:44:38 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/20 19:21:23 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	ft_init_player(t_player *player)
{
	player->rot_angle = M_PI_2;
	player->p_height = 1;
	player->p_width = 1;
	player->planeX = 0;
	player->planeY = 0.66;
	player->raydirX = 0;
	player->raydirY = 0;
	player->posX = 0;
	player->posY = 0;
	player->dirX = 0;
	player->dirY = 0;
	player->b_mapX = 0;
	player->b_mapY = 0;
	player->mov_speed = 3.0;
	player->side_distX = fabs(1 / player->raydirX);
	player->side_distY = fabs(1 / player->raydirY);
	player->hit = 0;
	player->pix = 0;
}

static void		next_step(t_player *player)
{
	if (player->raydirX < 0)
	{
		player->stepX = -1;
		player->side_distX = (player->posX - player->b_mapX) * player->delta_distX;
	}
	else
	{
		player->stepX = 1;
		player->side_distX = (player->b_mapX + 1.0 - player->posX) * player->delta_distX;
	}
	if (player->raydirY < 0)
	{
		player->stepY = -1;
		player->side_distY = (player->posY - player->b_mapY) * player->delta_distY;
	}
	else
	{
		player->stepY = 1;
		player->side_distY = (player->b_mapY + 1.0 - player->posY) * player->delta_distY;
	}
}

void		perp_and_height(t_player *player, t_all *all)
{
	if (all->player.side == 0 || all->player.side == 1)
		all->player.perp_wall_dist = (all->player.b_mapX - all->player.posX + (1 - all->player.stepX) / 2)
		/ all->player.raydirX;
	else
		all->player.perp_wall_dist = (all->player.b_mapY - all->player.posY + (1 - all->player.stepY) / 2)
		/ all->player.raydirY;
	all->player.line_height = (int)(all->maps.resy / all->player.perp_wall_dist);
	all->player.draw_start = (-all->player.line_height / 2 + ((all->maps.resy / 2)
		* all->player.cam_height));
	if (all->player.draw_start < 0)
		all->player.draw_start = 0;
	all->player.draw_end = (all->player.line_height / 2 + ((all->maps.resy / 2)
		* all->player.cam_height));
	if (all->player.draw_end >= all->maps.resy)
		all->player.draw_end = all->maps.resy - 1;
}

static void	predict_wall_face(t_player *player)
{
	if (player->side_distX < player->side_distY)
	{
		player->side_distX += player->delta_distX;
		player->b_mapX += player->stepX;
		if (player->stepX == 1)
			player->side = 0;
		else if (player->stepX == -1)
			player->side = 1;
	}
	else
	{
		player->side_distY += player->delta_distY;
		player->b_mapY += player->stepY;
		if (player->stepY == 1)
			player->side = 2;
		else if (player->stepY == -1)
			player->side = 3;
	}
}
void hit(t_player *player, t_all *all)
{
	while (all->player.hit == 0)
	{
		predict_wall_face(player);
		if (all->maps.mtx[all->player.b_mapY][all->player.b_mapX] > '0'
		&& all->maps.mtx[all->player.b_mapY][all->player.b_mapX] != '2')
			all->player.hit = 1;
		// else if (all->maps.mtx[all->player.b_mapY][all->player.b_mapX] == '2')
		// 	// is_sprite(all);
	}
}

static void		do_raycasting(t_all *all, t_player *player)
{
	ft_init_player(&all->player);
	next_step(&all->player);
	hit(player, all);
	perp_and_height(player, all);
	//ray->z_buffer[ray->pix] = ray->perp_wall_dist;
	//texturisation(ray, win_infos);
	all->player.pix++;
}

int		 ft_raycasting(t_all *all)
{
	t_player *player;

	if (!(player = malloc(sizeof(t_player))))
		return (0);
	ft_bzero(player, sizeof(t_player));
	while (player->pix < all->maps.mapx)
		do_raycasting(all, player);
	// if (!draw_sprite(ray, win_infos))
	// 	return (ERROR);
	// if (win_infos->save == 1)
	// {
	// 	win_infos->save = 0;
	// 	create_bitmap(win_infos->img, "cub3D");
	// 	leave(0, win_infos, "");
	// }
	mlx_put_image_to_window(all->vars.mlx, all->vars.win,
		all->data.img, 0, 0);
	// free(ray->z_buffer);
	free(player);
	return (1);
}