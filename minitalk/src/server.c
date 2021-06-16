/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:59:31 by jkosiara          #+#    #+#             */
/*   Updated: 2021/06/16 19:01:07 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_count(int sign)
{
	static int	i;
	static char	character;
	static int	index;
	static char	string[2048];

	i++;
	if (sign == SIGUSR2)
	{
		character = character << 1;
		character += 1;
	}
	else
		character = character << 1;
	if (i == 7)
	{
		string[index] = character;
		index++;
		if (character == 0)
		{
			ft_putstr_fd(string, 1);
			write(1, "\n", 1);
			index = 0;
		}
		i = 0;
		character = 0;
	}
}

int	main(void)
{
	char	*pid_print;
	 int	id;

	id = getpid();
	pid_print = ft_itoa(id);
	ft_putstr_fd(pid_print, 1);
	write(1, "\n", 1);
	write(1, "Waiting for a signal...\n", 25);
	signal(SIGUSR1, ft_count);
	signal(SIGUSR2, ft_count);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
