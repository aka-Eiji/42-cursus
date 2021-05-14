/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:42 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/14 17:14:57 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             ft_close(int keycode, t_vars *vars)
{
    t_maps *all;
    /*mlx_destroy_window(vars->mlx, vars->win);*/
    printf("Game closed, thanks for playing!\n");
    exit(0);
    return (0);
}

int             key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == KEY_W)
         printf("You pressed W button, nice!\n");
    else if (keycode == KEY_A)
         printf("You pressed A button, nice!\n");
    else if (keycode == KEY_S)
         printf("You pressed S button, nice!\n");
    else if (keycode == KEY_D)
         printf("You pressed D button, nice!\n");
    return (0);
}