/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:42 by jkosiara          #+#    #+#             */
/*   Updated: 2021/04/27 19:15:02 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             close(int keycode, t_vars *vars)
{
    /*mlx_destroy_window(vars->mlx, vars->win);*/
    printf("Game closed, thanks for playing!\n");
    exit(0);
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
}

int             main(int argc, char **argv)
{
    t_vars      vars;
    t_data      img;
    int         i;
    int         j;
    
    i = 0;
    vars.mlx = mlx_init();
    if (argc != 3)
    {
        printf("Error, insert a value please. \n");
        exit (0);
    }
    else
    {
        vars.win = mlx_new_window(vars.mlx, 1920, 1080,  "Il gioco dell'anno!");
    }
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);
} 