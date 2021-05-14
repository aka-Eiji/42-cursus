/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:06:44 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/14 17:39:43 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3d.h"

void	ft_res(char *newline, t_maps *maps)
{
	char	*tmp;
	int		i;

	i = 0;
	int resmaxx;
	int resmaxy;

	resmaxx = 2560;
	resmaxy = 1440;
	maps->resx = 0;
	maps->resy = 0;
	tmp = ft_strtrim(newline, "R\t ");
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		maps->resx = (maps->resx * 10) + (tmp[i] - 48);
		i++;
	}
	while (tmp[i] == '\t' || tmp[i] == ' ')
		i++;
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		maps->resy = (maps->resy * 10) + (tmp[i] - 48);
    	i++;
	}
	if (maps->resx > 2560)
		maps->resx = resmaxx;
	if (maps->resy > 1440)
		maps->resy = resmaxy; 
	free(tmp);
}

void	ft_textures(t_maps *maps, char *newline) 
{
	char	*tmp;
	int		i;

	i = 0;
	if (newline[i] == 'N')									//Lettura texture Nord
	{
		tmp = ft_strtrim(newline, "NO\t  ");
		maps->NO = tmp;
	}
	else if (newline[i] == 'S' && newline[1] == 'O')			//Lettura texture Sud
	{
		tmp = ft_strtrim(newline, "SO\t ");
		maps->SO = tmp;
	}
	else if (newline[i] == 'E' && newline[1] == 'A')			//Lettura texture Est
	{
		tmp = ft_strtrim(newline, "EA\t ");
		maps->EA = tmp;
	}
	else if (newline[i] == 'W' && newline[1] == 'E')			//Lettura texture Ovest
	{
		tmp = ft_strtrim(newline, "WE\t ");
		maps->WE = tmp;
	}
	else if (newline[i] == 'S')								//Lettura texture Sprite
	{
		tmp = ft_strtrim(newline, "S\t ");
		maps->S = tmp;
	}
}

void	ft_parsemap(t_maps *maps, char *newline)
{
    int		i;
    int		fd;
	char	*tmp1;
	t_all	all;
	char **tmp_cell;

	ft_init(maps);
	i = 0;
    fd = open("include/maps/maps.cub", O_RDONLY);
    while (gnl(fd, &newline))
    {
		tmp1 = newline;
		if (tmp1[0] == 'R')
			ft_res(tmp1, maps); 
		else if (tmp1[0] == 'N')
			ft_textures(maps, tmp1);
		else if (tmp1[0] == 'S')
			ft_textures(maps, tmp1);
		else if (tmp1[0] == 'E')
		 	ft_textures(maps, tmp1);
		else if (tmp1[0] == 'W')
		 	ft_textures(maps, tmp1);
		else if (tmp1[0] == 'F' || tmp1[i] == 'C')
			ft_colors(tmp1, maps);
		else if (tmp1[0] == '1' || tmp1[0] == ' ' || tmp1[0] == '\t')
		{
			ft_count_y(maps, tmp1);
			//ft_cell(maps, newline, &i);
			tmp_cell = ft_check_rows(maps, tmp1, &i);	
		}
	}
	free(tmp1);
}