/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:23:45 by jkosiara          #+#    #+#             */
/*   Updated: 2020/12/08 17:45:37 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int k;

	i = 0;
	k = 0;

	while (dest[k] != '\0')
	{
		k++;
	}
	while (src[i] != '\0' && i < size)
	{
		dest[k + i] = src[i];
		i++;
        k++;
	}

	if (i < size - 1)
		dest[i] = 0;
	else
		dest[size - 1] = 0;
	return (i);
}

int main()
{
	char source[] = {"original Song Original mix"};
	char destination[] = {"Pendulum The island"};

	ft_strlcpy(destination, source, 50);
	
	printf("%s", destination);
}
