/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:01:43 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/13 14:13:30 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*charjoin(char *s, char c, int max)
{
	char	*ret;
	int		i;

	ret = malloc(max + 2);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i++] = c;
	ret[i] = 0;
	free(s);
	return (ret);
}

int	gnl(int fd, char **line)
{
	char	c;
	int		i;
	int		max;

	i = 0;
	max = 0;
	if (line == 0)
		return (-1);
	*line = malloc(1);
	*line[0] = 0;
	i = read(fd, &c, 1);
	while (i > 0)
	{
		if (c == '\n')
			break ;
		*line = charjoin(*line, c, max++);
		i = read(fd, &c, 1);
	}
	if (i < 0)
		return (-1);
	if (i)
		return (1);
	return (0);
}
