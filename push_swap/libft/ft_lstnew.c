/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:24:27 by jkosiara          #+#    #+#             */
/*   Updated: 2021/02/01 16:25:37 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_new;

	if (!(l_new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	l_new->content = content;
	l_new->next = 0;
	return (l_new);
}
