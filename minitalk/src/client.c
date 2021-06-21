/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolla <jolla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:27:40 by jkosiara          #+#    #+#             */
/*   Updated: 2021/06/21 17:36:48 by jolla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_eightbit(char character)
{
	int		i;
	char	*result;

	result = malloc(sizeof(8));
	if (result == 0)
		exit(0);
	result[7] = 0;
	i = 6;
	while (character > 1)
	{
		result[i] = (character % 2) + 48;
		character /= 2;
		i--;
	}
	result[i] = (character % 2) + 48;
	i--;
	while (i >= 0)
	{
		result[i] = 48;
		i--;
	}
	return (result);
}

void	ft_send_term(int pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(10);
	}
}

void	ft_send_signal(int pid, char *string)
{
	int					pid;
	int					i;
	char				*string;

	i = 0;
	while (string[i])
	{
		temp = ft_eightbit(string[i]);
		j = 0;
		while (temp[j])
		{
			if (temp[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(10);
		}
		i++;
	}
	ft_send_term(pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	char				*string;

	if (argc != 3)
		exit(0);
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		write (1, "PID not valid.. \n", 18);
		return (0);
	}
	write(1, "signal sended. \n", 25);
	string = argv[2];
	ft_send_signal(pid, string);
}
