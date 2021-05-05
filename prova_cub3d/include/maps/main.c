/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:19:30 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/05 17:53:53 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


int  main(int argc, char **argv)
{
	t_maps      maps;
  	t_vars      vars;
    t_data      img;
	char        *newline;
    
    vars.mlx = mlx_init();
    ft_parsemap(&maps, newline);
    printf("\nRESOLUTION\n");
	printf("resx %d\nresy %d\nNO %s\nSO %s\nEA %s\nWE %s\nS %s\n\n", maps.resx, maps.resy, maps.NO, maps.SO, maps.EA, maps.WE, maps.S);
    printf("COLORS\n");
    printf("Red %d\nGreen %d\nBlue %d\n\n", maps.red, maps.green, maps.blue);
    printf("FLOOR & CEILING\n");
	printf("Floor %X\nCeiling %X\n\n", maps.F, maps.C);
    if (argc != 2)
    {
        printf("Error, insert a value please. \n");
        exit (0);
    }
    vars.win = mlx_new_window(vars.mlx, maps.resx, maps.resy, "Il gioco dell'anno!");
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<0, ft_close, &vars);
    mlx_loop(vars.mlx);
}