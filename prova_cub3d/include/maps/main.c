/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:19:30 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/20 19:22:07 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int  main(int argc, char **argv)
{
  	// t_vars      vars;
    // t_data      img;
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
    printf("\nRESOLUTION\n");
	printf("resx %d\nresy %d\n", all.maps.resx, all.maps.resy);
    printf("\nCOORDS & SPRITES\n");
    printf("NO %s\nSO %s\nEA %s\nWE %s\nSP %s\n\n", all.maps.NO, all.maps.SO, all.maps.EA, all.maps.WE, all.maps.S);
    printf("COLORS\n");
    printf("Red %d\nGreen %d\nBlue %d\n\n", all.maps.red, all.maps.green, all.maps.blue);
    printf("FLOOR & CEILING\n");
	printf("Floor %X\nCeiling %X\n\n", all.maps.F, all.maps.C);
    printf("MAPS COORDINATES\n");
    printf("Y %d\n", all.maps.mapy);
    printf("X %d\n", all.maps.mapx);
    // printf("PosY %f\n", all.player.posY);
    // printf("PosX %f\n", all.player.posX);
	// printf("dirY %f\n", all.player.dirY);
    // printf("dirX %f\n", all.player.dirX);
    all.vars.win = mlx_new_window(all.vars.mlx, all.maps.resx, all.maps.resy, "Cub3D");
    ft_draw_map(&all.vars, &all.maps);
    ft_raycasting(&all);
    // draw_line(&all.player, &all.vars);
    mlx_key_hook(all.vars.win, key_hook, &all.vars);
    mlx_hook(all.vars.win, 17, 1L<<0, ft_close, &all.vars);
    mlx_loop(all.vars.mlx);
}