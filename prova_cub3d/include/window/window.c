/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:42 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/25 15:55:46 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             ft_error(int n)
{
    if (n == 1)
        printf("Error: invalid textures!\n");
    if (n == 2)
        printf("Error: Map not valid!\n");
    if (n == 3)
        printf("Error: \n");
    exit (0);
    return (0);
}

int             ft_close(int keycode, t_all *all)
{
    //mlx_destroy_window(vars->mlx, vars->win);
    printf("Game closed, thanks for playing!\n");
    exit(0);
    return (0);
}

int             key_hook(int keycode, t_all *all)
{
    // double pa;

    if (keycode == 53)
        exit(0);
    else if (keycode == KEY_W)
    {
        printf("You pressed W button, nice!\n");
        all->player.posX += all->player.pdx;
        all->player.posY += all->player.pdy;
        // next_step(all);
        // mlx_loop_hook(all->vars.mlx, ft_render_next, &all);
        ft_render_next(all);
    }
    else if (keycode == KEY_A)
    {
        printf("You pressed A button, nice!\n");
        all->player.rot_angle -= 0.1;
        if (all->player.rot_angle < 0)
            all->player.rot_angle += 2 * M_PI;
        all->player.pdx = cos(all->player.rot_angle) * 5;
        all->player.pdy = sin(all->player.rot_angle) * 5;
        ft_render_next(all);
    }
    else if (keycode == KEY_S)
    {
        printf("You pressed S button, nice!\n");
        all->player.posX -= all->player.pdx;
        all->player.posY -= all->player.pdy;
        ft_render_next(all);
        printf("PosY %f\n", all->player.posY);
    }
    else if (keycode == KEY_D)
    {
        printf("You pressed D button, nice!\n");
        all->player.rot_angle += 0.1;
        if (all->player.rot_angle > 2 * M_PI)
            all->player.rot_angle -= 2 * M_PI;
        all->player.pdx = cos(all->player.rot_angle) * 5;
        all->player.pdy = sin(all->player.rot_angle) * 5;
        ft_render_next(all);
    }
    return (0);
}