/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:42 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/26 15:57:37 by mmurello         ###   ########.fr       */
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
    ft_init_keys(all);
    if (keycode == 53)
        exit(0);
    else if (keycode == KEY_W)
    {
        all->keys.up = 1;
        ft_keys(all);
        ft_render_next(all);
    }
    else if (keycode == KEY_A)
    {
        all->keys.left = 1;
        ft_keys(all);
        ft_render_next(all);
    }
    else if (keycode == KEY_S)
    {
        all->keys.down = 1;
        ft_keys(all);
        ft_render_next(all);
    }
    else if (keycode == KEY_D)
    {
        all->keys.right = 1;
        ft_keys(all);
        ft_render_next(all);
    }
    return (0);
}