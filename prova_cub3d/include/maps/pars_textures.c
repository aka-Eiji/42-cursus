/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:06:44 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/24 17:32:22 by mmurello         ###   ########.fr       */
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
	char 	*str;

	i = 0;
	temp = malloc(sizeof(*temp) * ((*my) + 1));
	while (i < *my)
	{
		str = str_to_map_rows(tb[i]);
		temp[i] = ft_strdup(str);
		free(str);
		i++;
	}
	temp[i] = 0;
	free_matrix(tb);
	(*my)++;
	tb = malloc(sizeof(*tb) * ((*my) + 1));
	i = 0;
	while (i < *my - 1)
	{
		str = str_to_map_rows(temp[i]);
		tb[i] = ft_strdup(str);
		free(str);
		i++;
	}
	str = str_to_map_rows(newline);
	tb[i] = ft_strdup(str);
	tb[i + 1] = 0;
	free_matrix(temp);
	if (ft_strlen(tb[i]) > *mx)
		*mx = ft_strlen(tb[i]);
	return (tb);
}

int		ft_parsemap(t_all *all, char *newline)
{
    int		i;
    int		fd;
	char 	**tmp_cell;

	tmp_cell = malloc(sizeof(*tmp_cell));
	tmp_cell[0] = 0;
	ft_init(&all->maps);
    fd = open("include/maps/maps.cub", O_RDONLY);
    while (gnl(fd, &newline))
    {
		if (newline[0] == 'R')
			ft_res(newline, &all->maps); 
		else if (newline[0] == 'N' || newline[0] == 'S' || newline[0] == 'W' || newline[0] == 'E')
			ft_textures(&all->maps, newline);
		else if (newline[0] == 'F' || newline[0] == 'C')
			ft_colors(newline, &all->maps);
		else if (newline[0] == '1' || newline[0] == ' ' || newline[0] == '\t')
			tmp_cell = ft_write_map(newline, &all->maps.mapy, &all->maps.mapx, tmp_cell);	
	}
	all->maps.mtx = tmp_cell;
	ft_pos(&all->maps, &all->player);
	// i = 0;
	if (ft_validmap(&all->maps) == 2)
		ft_error(2);

	// while (i < all->maps.mapy)
	// {
	// 	printf("mtx %p %s\n", all->maps.mtx[i], all->maps.mtx[i]);
	// 	i++;
	// }
	free(newline);
	return (0);
}
