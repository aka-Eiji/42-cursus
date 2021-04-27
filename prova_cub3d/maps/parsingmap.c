/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/04/27 17:19:21 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

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

void ft_parsemap(t_all)
{
    t_maps resx;
    t_maps resy;
    int i;
    int fd;
    char *newline;
    int resolution;

    fd = open("maps.cub", O_RDONLY);
    while (gnl(fd, *newline))
    {
        if (newline[0] == 'R')
        {
            ft_strtrim()
            while(newline[i] >='0' && newline[i] <='9')
            {
                resolution=ft_strjoin(resolution, newline[i]);
                i++;
            }
        resx = resolution;
        }   
    } 
    
    
    
    
}