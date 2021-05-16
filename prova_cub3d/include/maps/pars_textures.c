/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:06:44 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/16 15:37:23 by mmurello         ###   ########.fr       */
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

static char **ft_malloc_map(t_maps *maps)
{
	char **tmp;
	int j;

	tmp = malloc(sizeof(char *) * (maps->mapy + 1));
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, sizeof(char *) * (maps->mapy + 1));
	j = 0;
	while (j < maps->mapy)
	{
		tmp[j] = malloc(sizeof(char *) * (maps->mapx + 1));
		if (tmp[j] == NULL)
			return (NULL);
		ft_bzero(tmp[j], sizeof(char *) * (maps->mapx + 1));
		j++;
	}
	return (tmp);
}

static char		**fill_map(char *newline, char **map, t_maps *maps)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	i = 0;
	while (y < maps->mapy)
	{
		x = 0;
		while (newline[i] && newline[i] != '\0')
		{
			if(!ft_jumpspace(newline[i]))
				map[y][x++] = newline[i];
			// se newline uguale a coordinate fuzione che setta la posizione di start
			i++;
		}
		map[y++][x] = '\0';
		i += 1;
	}
	return (map);
}

// static char		**print_matrix(t_maps *maps, char **map, char *newline)
// {
// 	while ()
// }

void	ft_parsemap(t_maps *maps, char *newline)
{
    int		i;
    int		fd;
	char	*tmp1;
	t_all	all;
	static char 	**tmp_cell;
	int j = 0;

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
		else if (tmp1[0] == 'F' || tmp1[0] == 'C')
			ft_colors(tmp1, maps);
		else if (tmp1[0] == '1' || tmp1[0] == ' ' || tmp1[0] == '\t')
		{
			ft_count_y(maps, tmp1);
			ft_count_cells(maps, tmp1);
			tmp_cell = ft_malloc_map(maps);
			tmp_cell = fill_map(tmp1, tmp_cell, maps);
			printf("tmp_cell prima %p - %s\n", tmp_cell, *tmp_cell);
			// printf("tmp_cell dopo %p - %s\n", tmp_cell, *tmp_cell);
			//ft_cell(maps, newline, &i);
		}
		// maps->mtx = tmp_cell;
	}
	// while (maps->mtx[i] !=  '\0')
	// {
		// printf("maps %s\n", *maps->mtx);
		// i++;
	// }
	free(tmp1);
}