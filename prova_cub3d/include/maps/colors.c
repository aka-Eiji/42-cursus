/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:04:42 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/04 14:06:11 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			ft_create_rgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8| b); 
}

int			ft_check_virg(int i, char *newline)
{
	if (newline[i] == ',' || newline[i] == ' ')
	{
		i++;
		return(i);
	}
	return(i);
}

void		ft_check_rgb(int i, char *newline, t_maps *maps)
{
	while (newline[i] != '\0')
	{
		while (newline[i] >= '0' && newline[i] <= '9' && i < 3)
		{
			maps->red = (maps->red * 10) + (newline[i] - 48);
			i++;
			ft_check_virg(i, newline);
		}
		while (newline[i] >= '0' && newline[i] <= '9' && i < 6)
		{
			maps->green = (maps->green * 10) + (newline[i] - 48);
			i++;
			ft_check_virg(i, newline);
		}
		while (newline[i] >= '0' && newline[i] <= '9' && i > 6)
		{
			maps->blue = (maps->blue * 10) + (newline[i] - 48);
			i++;
			ft_check_virg(i, newline);
		}
		i++;
	}
}

void		ft_colors(char *newline, t_maps *maps)
{
	char	*tmp;
	int		i;

	maps->red = 0;
	maps->green = 0;
	maps->blue = 0;
	i = 0;
	tmp = newline;
	while(tmp[i] != '\0')
	{
		if(tmp[i] == 'F')
		{	
			tmp = ft_strtrim(newline, "F\t ");
			ft_check_rgb(i, tmp, maps);
			maps->F = ft_create_rgb(0, maps->red, maps->green, maps->blue);
		}
		else if(tmp[i] == 'C')
		{
			tmp = ft_strtrim(newline, "C\t ");
			ft_check_rgb(i, tmp, maps);
			maps->C = ft_create_rgb(0, maps->red, maps->green, maps->blue);
		}
		i++;
	}
}