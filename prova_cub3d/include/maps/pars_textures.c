/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:06:44 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/04 17:11:00 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_res(char *newline, t_maps *maps)
{
	char	*tmp;
	int		i;

	i = 0;
	maps->resx = 0;
	maps->resy = 0;
	tmp = ft_strtrim(newline, "R\t ");
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		maps->resx = (maps->resx * 10) + (tmp[i] - 48);
		i++;
	}
/*manca l'impostazione della risoluzione massima fissata a (2560 x 1440) anche se maps->resx > 2560 || maps-> resy > 1440*/

	while (tmp[i] == '\t' || tmp[i] == ' ')
		i++;
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		maps->resy = (maps->resy * 10) + (tmp[i] - 48);
    	i++;
	}
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
	
	i = 0;
    fd = open("/Users/mmurello/Documents/42/cub3d/prova_cub3d/prova_cub3d/include/maps/maps.cub", O_RDONLY);
    while (gnl(fd, &newline))
    {
		tmp1 = newline;
		if (tmp1[i] == 'R')
			ft_res(tmp1, maps); 
		else if (tmp1[i] == 'N')
			ft_textures(maps, tmp1);
		else if (tmp1[i] == 'S')
			ft_textures(maps, tmp1);
		else if (tmp1[i] == 'E')
		 	ft_textures(maps, tmp1);
		else if (tmp1[i] == 'W')
		 	ft_textures(maps, tmp1);
		else if (tmp1[i] == 'F' || tmp1[i] == 'C')
			ft_colors(tmp1, maps);
    }
	free(tmp1);
}

// int main()
// {
// 	char *newline;
// 	t_maps maps;

// 	ft_parsemap(&maps, newline);
// 	printf("resx %d\n", maps.resx);
// }