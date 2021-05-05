/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:19:30 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/05 17:43:28 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


int  main(int argc, char **argv)
{
	t_maps      maps;
  	t_vars      vars;
    t_data      img;
	char        *newline;
    // char        *tmp1;
    // char        *tmp2;
    // int         res1;
    // int         res2;

    // tmp1 = argv[1];
    // tmp2 = argv[2];
    // res1 = ft_atoi(tmp1);
    // res2 = ft_atoi(tmp2);
    vars.mlx = mlx_init();
    ft_parsemap(&maps, newline);
	printf("resx %d\nresy %d\n NO %s\n SO %s\n EA %s\n WE %s\n S %s\n", maps.resx, maps.resy, maps.NO, maps.SO, maps.EA, maps.WE, maps.S);
    printf("red %d\ngreen %d\nblue %d\n", maps.red, maps.green, maps.blue);
	printf("F %X\nC %X\n", maps.F, maps.C);
    // if (argc != 3)
    // {
    //      printf("Error, insert a value please. \n");
    //      exit (0);
    // }
    vars.win = mlx_new_window(vars.mlx, maps.resx, maps.resy, "Il gioco dell'anno!");
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<0, ft_close, &vars);
    mlx_loop(vars.mlx);
}