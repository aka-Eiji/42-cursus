/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:06:44 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/16 17:43:33 by mmurello         ###   ########.fr       */
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

char	**ft_write_map(char *newline, int *my, int *mx, char **tb)
{
	char	**temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(*temp) * ((*my) + 1));
	while (i < *my)
	{
		temp[i] = ft_strdup(tb[i]);
		i++;
	}
	temp[i] = 0;
	free_matrix(tb);
	(*my)++;
	tb = malloc(sizeof(*tb) * ((*my) + 1));
	i = 0;
	while (i < *my - 1)
	{
		tb[i] = ft_strdup(temp[i]);
		i++;
	}
	tb[i] = ft_strdup(newline);
	tb[i + 1] = 0;
//	free_matrix(temp);
	if (ft_strlen(newline) > *mx)
		*mx = ft_strlen(newline);
	return (tb);
}

void	ft_parsemap(t_maps *maps, char *newline)
{
    int		i;
    int		fd;
	t_all	all;
	char 	**tmp_cell;

	tmp_cell = malloc(sizeof(*tmp_cell));
	tmp_cell[0] = 0;
	ft_init(maps);
    fd = open("include/maps/maps.cub", O_RDONLY);
    while (gnl(fd, &newline))
    {
		if (newline[0] == 'R')
			ft_res(newline, maps); 
		else if (newline[0] == 'N' || newline[0] == 'S' || newline[0] == 'W' || newline[0] == 'E')
			ft_textures(maps, newline);
		else if (newline[0] == 'F' || newline[0] == 'C')
			ft_colors(newline, maps);
		else if (newline[0] == '1' || newline[0] == ' ' || newline[0] == '\t')
			tmp_cell = ft_write_map(newline, &maps->mapy, &maps->mapx, tmp_cell);	
	}
	i = 0;
	while (i < maps->mapy)
	{
		printf("tmp %p %s\n", tmp_cell[i], tmp_cell[i]);
		i++;
	}
	free(newline);
}