/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:56:37 by mmurello          #+#    #+#             */
/*   Updated: 2021/05/21 16:16:02 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		is_map_char(char c, char *mapchars)
{
	int i;

	i = 0;
	while (mapchars[i])
	{
		if (mapchars[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*str_to_map_rows(char *str)
{
	int len;
	char *temp;
	char *final_str;
	int i;
	int j;

	j = 0;
	i = 0;
	len = ft_strlen(str);
	temp = malloc(len + 1);
	while(str[i])
	{
		if (is_map_char(str[i], "012NSEW"))
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	temp[j] = 0;
	// len = ft_strlen(temp);
	// final_str = malloc (len + 1);
	final_str = ft_strdup(temp);
	// final_str[len] = 0;
	free(temp);
	return (final_str);
}
