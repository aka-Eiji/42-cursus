/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/04/30 17:55:34 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../cub3d.h"
#include <stdio.h>

char *charjoin(char *s, char c, int max)
{
	char *ret = malloc(max + 2);
	int i = -1;
	while(s[++i])
		ret[i] = s[i];
	ret[i++] = c;
	ret[i] = 0;
	free(s);
	return (ret);
}

int gnl(int fd, char **line)
{
	char c;
	int i, max = 0;
	if(line == 0)
		return -1;
	*line = malloc(1);
	*line[0] = 0;
	i = read(fd, &c, 1);
	while(i > 0)
	{
		if(c == '\n')
			break;
		*line = charjoin(*line, c, max++);
		i = read(fd, &c, 1);
	}
	if (i < 0)
		return (-1);
	if (i)
		return (1);
	return (0);
	
}

void	ft_res(char *newline, t_maps *maps)
{
	char *tmp;
	int i;

	i = 0;
	maps->resx = 0;
	maps->resy = 0;
    tmp = ft_strtrim(newline, "R\t ");
    while(tmp[i] >= '0' && tmp[i] <= '9')
    {
    	maps->resx = (maps->resx * 10) + (tmp[i] - 48);
        i++;
    }
	while(tmp[i] == '\t' || tmp[i] == ' ')
		i++;
	while(tmp[i] >= '0' && tmp[i] <= '9')
	{
		maps->resy = (maps->resy * 10) + (tmp[i] - 48);
        i++;
	}
	free(tmp);
}

void	ft_textures(t_maps *maps, char *newline)
{
	char *tmp;
	int i;

	i = 0;
	if(newline[i] == 'N')
	{
		tmp = ft_strtrim(newline, "NO\t  ");
		maps->NO = tmp;
	}
	else if(newline[i] == 'S' && newline[1] == 'O')
	{
		tmp = ft_strtrim(newline, "SO\t ");
		maps->SO = tmp;
	}
	else if(newline[i] == 'E' && newline[1] == 'A')
	{
		tmp = ft_strtrim(newline, "EA\t ");
		maps->EA = tmp;
	}
	else if(newline[i] == 'W' && newline[1] == 'E')
	{
		tmp = ft_strtrim(newline, "WE\t ");
		maps->WE = tmp;
	}
	/*else if(newline[i] == 'S')
	{
		tmp = ft_strtrim(newline, "S\t ");
		maps->S = tmp;
	}	*/
}

void	ft_parsemap(t_maps *maps, char *newline)
{
    int i;
    int fd;
	char *tmp1;
	
	i = 0;

    fd = open("maps.cub", O_RDONLY);
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
		else if (tmp1[i] == 'S')
		 	ft_textures(maps, tmp1);
    }
}


int main()
{
	t_maps maps;
	char *newline;
	
	ft_parsemap(&maps, newline);
	printf("resx %d\nresy %d\n NO %s\n SO %s\n EA %s\n WE %s\n", maps.resx, maps.resy, maps.NO, maps.SO, maps.EA, maps.WE);
	return 0;
}
