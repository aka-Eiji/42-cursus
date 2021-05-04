/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:19:30 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/04 14:22:43 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int  main()
{
	t_maps maps;
	char *newline;

	ft_parsemap(&maps, newline);
	printf("resx %d\nresy %d\n NO %s\n SO %s\n EA %s\n WE %s\n S %s\n", maps.resx, maps.resy, maps.NO, maps.SO, maps.EA, maps.WE, maps.S);
	printf("red %d\ngreen %d\nblue %d\n", maps.red, maps.green, maps.blue);
	printf("color %X\n", ft_create_rgb(0, maps.red, maps.green, maps.blue));
	printf("F %X\nC %X\n", maps.F, maps.C);
	 return (0);
}