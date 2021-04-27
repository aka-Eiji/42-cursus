/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/04/27 20:47:16 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../cub3d.h"

typedef struct s_maps{
        int resx;
        int resy;
        
}              t_maps;


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

void ft_parsemap(t_maps *maps)
{
    int i;
    int fd;
    char *newline;
    int resolution;
    char *tmp;
	i = 0;
	maps->resx = 0;

	resolution = 0;
    fd = open("maps.cub", O_RDONLY);
    while (gnl(fd, &newline))
    {
			
        if (newline[i] == 'R')
        {
            tmp = ft_strtrim(newline, "R\t ");
            while(tmp[i] >='0' && tmp[i] <='9')
            {
                maps->resx = (maps->resx * 10) + (tmp[i] - 48);
                i++;
            }
			while(tmp[i] != )
			{
				if ()	
			}
			printf("%d\n", i);
		
        }
    } 
}
#include <stdio.h>
int main()
{
	t_maps maps;
	ft_parsemap(&maps);
	printf("%d\n%d\n", maps.resx, maps.resy);
	return 0;
}
