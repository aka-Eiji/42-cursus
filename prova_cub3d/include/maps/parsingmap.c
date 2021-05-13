/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/13 18:09:23 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3d.h"

void ft_init(t_maps *maps)
{	
	maps->mapx = 0;
	maps->mapy = 0;
	maps->mtx = NULL;
}

int		ft_jumpspace(char *newline, int i)
{
	while ((newline[i] == ' ' || newline[i] == '\t' || newline[i] == '\n')
	|| (newline[i] == '\r' || newline[i] == '\v' || newline[i] == '\f'))
		(i)++;
	return (i);
}

int ft_count_y(t_maps *maps, char *newline)
{
	int i;

	i = 0;
	if (newline[0] != '1')
	{
		i = ft_jumpspace(newline, i);
		if (newline[i] == '1')
		{
			maps->mapy++;
			newline++;
		}
	}
	else if (newline[0] == '1')
	{
		maps->mapy++;
		newline++;
	}
		return (maps->mapy);
}

int	ft_validmap(t_maps *maps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < NUM_ROWS)
	{
		j = 0;
		while (j < NUM_COLS)
		{
			if (maps->mtx[i][j] != '1' && i == 0)
				return (-1);
			else if (maps->mtx[i][j] != '1' && i == (NUM_ROWS - 1))
				return (-1);
			else if (maps->mtx[i][j] != '1' && j == 0)
				return (-1);
			else if (maps->mtx[i][j] != '1' && j == (NUM_COLS - 1))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_count_cells(t_maps *maps, char *newline)
{
	int i;
	int count;
	int n;

	i = 0;
	n = maps->mapx;
	count = 0;
	while(newline[i] != '\0')
	{
		if (newline[i] == '0' || newline[i] == '1' || newline[i] == '2' 
		|| newline[i] == 'W' || newline[i] == ' ' || newline[i] == 'E'
		|| newline[i] == 'S'|| newline[i] == 'N')
			count++;	
		i++;
 
	}
	if (count > n)
		maps->mapx = count;
	else
		maps->mapx = n;

	if (maps->mapx != 0 && maps->mapx != count)
		return (-1);
	return (maps->mapx);
}

char	*ft_cell(t_maps *maps, char *newline, int *i)
{
	int j;
    char *tmp;
    if (!(tmp = malloc(sizeof(char) * (ft_count_cells(maps, newline) + 1))))
        return NULL;
    j = 0;
    while (newline[*i] != '\0')
    {
        if (newline[*i] == '0' || newline[*i] == '1' || newline[*i] == '2' || newline[*i] == 'N')
            tmp[j++] = newline[*i];
        else if (newline[*i] == 'S' || newline[*i] == 'W' || newline[*i] == 'E' || newline[*i] == ' ')
            tmp[j++] = newline[*i];
        (*i)++;
    }
    tmp[j] = '\0';
	return (tmp);
}

// int ft_check_rows(t_maps *maps, char *newline, int i)
// {
// 	char **tmp;
// 	int j;

// 	if (!(tmp = malloc(sizeof(char *) * (NUM_ROWS + 1))))
// 		return (-1);
// 	j = -1;
// 	while (++j < NUM_ROWS)
// 		maps->mtx[j] = tmp[j];
// 	if ((tmp[j] = ft_cell(maps, newline, i)) == NULL)
// 		return (-1);
// 	tmp[NUM_ROWS] = NULL;
// 	if (NUM_ROWS > 0)
// 		free(maps->mtx);
// 	maps->mtx = tmp;
// 	NUM_ROWS++;
//  if ((maps->mapx = ft_count_cells(maps, newline)) == -1)
// 		return (-1);
// 	return (0);
// }