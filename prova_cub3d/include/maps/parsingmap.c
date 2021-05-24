/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:08 by jkosiara          #+#    #+#             */
/*   Updated: 2021/05/24 17:32:35 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3d.h"

void ft_init(t_maps *maps)
{	
	maps->mapx = 0;
	maps->mapy = 0;
	maps->mtx = NULL;
}

int		ft_jumpspace(int c)
{
	if ((c == ' ' || c == '\t' || c == '\n')
	|| (c == '\r' || c == '\v' || c == '\f'))
		return (1);
	return (0);
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
		while (j < ft_strlen(maps->mtx[i]))
		{
			if ((maps->mtx[i][j] != '1' && maps->mtx[i][j] != ' ') && i == 0)
				return (2);
			else if ((maps->mtx[i][j] != '1' && maps->mtx[i][j] != ' ') && i == (NUM_ROWS - 1))
				return (2);
			else if ((maps->mtx[i][j] != '1' && maps->mtx[i][j] != ' ') && j == 0)
				return (2);
			else if ((maps->mtx[i][j] != '1' && maps->mtx[i][j] != ' ') && j == (ft_strlen(maps->mtx[i]) - 1))
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}



// int ft_count_cells(t_maps *maps, char *newline)
// {
// 	int i;
// 	int count;
// 	int n;

// 	i = 0;
// 	n = maps->mapx;
// 	count = 0;
// 	while(newline[i] != '\0')
// 	{
// 		if (!ft_jumpspace(newline[i]))
// 			count++;
// 		i++;
// 	}
// 	if (count > n)
// 		maps->mapx = count;
// 	else
// 		maps->mapx = n;
	
// 	if (maps->mapx != 0 && maps->mapx != count)
// 		return (-1);
// 	return (maps->mapx);
// }

void	free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i] != 0)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
