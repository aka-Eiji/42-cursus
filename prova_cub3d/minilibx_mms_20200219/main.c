/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:42 by jkosiara          #+#    #+#             */
/*   Updated: 2021/04/30 18:14:13 by jkosiara         ###   ########.fr       */
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

int             ft_close(int keycode, t_vars *vars)
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

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}
int             main(int argc, char **argv)
{
    t_vars      vars;
    t_data      img;
    char        *tmp1;
    char        *tmp2;
    int         res1;
    int         res2;
    
    tmp1 = argv[1];
    tmp2 = argv[2];
    res1 = ft_atoi(tmp1);
    res2 = ft_atoi(tmp2);
    vars.mlx = mlx_init();
    if (argc != 3)
    {
        printf("Error, insert a value please. \n");
        exit (0);
    }
    else
    {
        vars.win = mlx_new_window(vars.mlx, res1, res2,  "Il gioco dell'anno!");
    }
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<0, ft_close, &vars);
    mlx_loop(vars.mlx);
} 