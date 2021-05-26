/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:19:30 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/26 15:58:10 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int     ft_render_next(t_all *all)
{
    ft_draw_map(&all->vars, &all->maps);
    ft_draw_player(all);
    ft_draw_line(all);
    // ft_move_player(all);
    return(1);
}

int  main(int argc, char **argv)
{
    t_all       all;
	char        *newline;
    int i;
    int j;
    i = 0;
    j = 0;
    // if (argc != 2)
    // {
    //     printf("Error, insert a value please. \n");
    //     exit (0);
    // }
    all.vars.mlx = mlx_init();
    ft_parsemap(&all, newline);
    all.vars.win = mlx_new_window(all.vars.mlx, all.maps.resx, all.maps.resy, "Cub3D");
    mlx_key_hook(all.vars.win, key_hook, &all.vars);
    mlx_hook(all.vars.win, 17, 1L<<0, ft_close, &all.vars);
    mlx_loop_hook(all.vars.mlx, ft_render_next, &all);
    mlx_loop(all.vars.mlx);
}