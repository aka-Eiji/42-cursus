/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:16:11 by jkosiara          #+#    #+#             */
/*   Updated: 2021/09/21 15:05:13 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	ft_put_in_list(t_list **lst, char *input)
{
	int	*temp;

	while (*input)
	{
		if (ft_isspace(*input))
			input++;
		else if (ft_isdigit(*input) || *input == '-' || *input == '+')
		{
			temp = ft_malloc(1, sizeof(int *));
			if (!temp)
				;
			*temp = ft_atoi(&input);
			ft_lstadd_back(lst, ft_lstnew((void *)temp));
		}
		else
			;
	}
}