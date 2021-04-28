/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/04/28 17:15:43 by mmurello         ###   ########.fr       */
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
	while((i = read(fd, &c, 1)) > 0)
	{
		if(c == '\n')
			break;
		*line = charjoin(*line, c, max++);
	}
	if (i == -1)
		return(-1);
	return i == 0 ? 0 : 1;
}

void	ft_parsemap(t_maps *maps, char *newline)
{
    int i;
    int fd;
    char *tmp;
	char **tmp1;

	i = 0;
	maps->resx = 0;
	maps->resy = 0;
    fd = open("maps.cub", O_RDONLY);
    while (gnl(fd, &newline))
    {	
        if (newline[i] == 'R')
        {
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
    }
	if(newline)
		tmp1 = ft_split(newline, '\n');
	printf("%s\n", tmp1[0][1]);
}


// void	texture(t_maps *t_maps, char *newline)
// {
// 	char **tmp;

// }



int main()
{
	t_maps maps;
	char *newline;
	ft_parsemap(&maps, newline);
	// texture(&maps, newline);
	printf("resx %d\nresy %d\n", maps.resx, maps.resy);
	return 0;
}
