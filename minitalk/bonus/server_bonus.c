/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:02:16 by jkosiara          #+#    #+#             */
/*   Updated: 2021/07/01 18:11:19 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	ft_endstring(char character, int sign)
{
	if (sign == SIGUSR2)
	{
		character = character << 1;
		character += 1;
	}
	else
		character = character << 1;
	return (character);
}

void	ft_count(int sign)
{
	static int		i;
	static char		character;
	static int		index;
	static char		string[2048];

	i++;
	character = ft_endstring(character, sign);
	if (i == 8)
	{
		string[index] = character;
		index++;
		if (character == 0)
		{
			write(1, "signal received: ", 18);
			ft_putstr_fd(string, 1);
			index = 0;
		}
		i = 0;
		character = 0;
	}
}

int	main(void)
{
	int		id;
	char	*pid_print;

	id = getpid();
	pid_print = ft_itoa(id);
	ft_putstr_fd(pid_print, 1);
	write(1, "Waiting for a signal...\n", 25);
	signal(SIGUSR1, ft_count);
	signal(SIGUSR2, ft_count);
	while (1)
	{
		usleep(100);
	}
	return (0);
}
