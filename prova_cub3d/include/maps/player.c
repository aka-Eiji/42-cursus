/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:44:38 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/21 18:04:05 by mmurello         ###   ########.fr       */
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

static void	texture_on_img(t_line *line, t_image *texture, t_all *all, t_player *player)
{
	int d;

	d = line->y * texture->size_line - (all->maps.resy
		* all->player.cam_height) * texture->size_line
		/ 2 + player->line_height * texture->size_line / 2;
	line->tex_y = ((d * texture->height) / player->line_height)
		/ texture->size_line;
	all->image->data[line->y * all->image->size_line + line->x
					* all->image->bpp / 8] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)];
	all->image->data[line->y * all->image->size_line + line->x
					* all->image->bpp / 8 + 1] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 1];
	all->image->data[line->y * all->image->size_line + line->x
					* all->image->bpp / 8 + 2] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 2];
}

void		ver_line_texture_image(t_line *line, t_all *all, t_image *texture, t_player *player)
{
	int y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			texture_on_img(line, texture, all, player);
			line->y++;
		}
	}
}

void		ver_line_color_image(t_line *line, t_all *all, int color)
{
	int y;
	int y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_put_to_image(color, line->x, y, all->image);
			y++;
		}
	}
}

static void	determine_side_draw(t_player *player,t_all *all,t_line *line, double wall_x)
{
	int		tex_x;
	t_image *img;

	all->data.img = all->textures[3];
	if (player->side == 1)
		img = all->textures[2];
	if (player->side == 2)
		img = all->textures[1];
	if (player->side == 3)
		img = all->textures[0];
	tex_x = (int)(wall_x * (double)img->width);
	if ((player->side == 0 || player->side == 1) && player->raydirX > 0)
		tex_x = img->width - tex_x - 1;
	if ((player->side == 2 || player->side == 3) && player->raydirY < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = player->draw_end;
	line->y1 = player->draw_start;
	line->tex_x = tex_x;
	ver_line_texture_image(line, all, img, player);
}

int			texturisation(t_all *all, t_player *player)
{
	double	wall_x;
	t_line	*line;

	if (!(line = malloc(sizeof(t_line))))
		return(-1);
	ft_bzero(line, sizeof(t_line));
	line->x = player->pix;
	if (player->side == 0 || player->side == 1)
		wall_x = all->player.posY + player->perp_wall_dist * player->raydirY;
	else
		wall_x = all->player.posX + player->perp_wall_dist * player->raydirX;
	wall_x -= floor(wall_x);
	if (all->maps.mtx[player->b_mapY][player->b_mapX] == '1')
		determine_side_draw(player, all, line, wall_x);
	line->y0 = 0;
	line->y1 = player->draw_start;
	ver_line_color_image(line, all, all->color_ceiling);
	line->y0 = all->maps.resy;
	line->y1 = player->draw_end;
	ver_line_color_image(line, all, all->color_floor);
	return (0);
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
	player->z_buffer[player->pix] = player->perp_wall_dist;
	texturisation(all, player);
	all->player.pix++;
}

int		 ft_raycasting(t_all *all)
{
	t_player *player;

	if (!(player = malloc(sizeof(t_player))))
		return (-1);
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
	return (0);
}