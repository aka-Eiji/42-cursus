/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:07:56 by jkosiara          #+#    #+#             */
/*   Updated: 2021/06/10 17:16:44 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char *ft_eightbit(char character)
{
    int i;
    char *result;

    result = malloc(sizeof(9));
    if (result == 0)
        exit(0);
    result[8] = 0;
    i = 7;
    while (character > 1)
    {
        result[i] = (character % 2) + 48;
        character /= 2;
        i--;
    }
    result[i] = (character % 2) + 48;
    i--;
    while(i >= 0)
    {
        result[i] = 48;
        i--;
    }
    return (result);
}
char	*ft_eightbit_pluse(char cara)
{
	char	*string;

	cara *= -1;
	string = ft_ctobit(cara);
	ft_string_complement(string);
	return (string);
}

void ft_send_term(int pid)
{
    int i;
    
    i = 0;
    while (i < 8)
    {
        kill(pid,SIGUSR1);
        i++;
        usleep(50);
    }
}

void ft_send_signal(int pid, char *string)
{
    int i;
    int j;
    char *temp;
    
    i = 0;
    while(string[i])
    {
        if (string[i] < 0)
            temp = ft_eightbit_pluse(string[i]);
        else
            temp = ft_eightbit(string[i]);
        j = 0;
        while(temp[j])
        {
            if (temp[j] == '0')
                kill(pid,SIGUSR1);
            else
                kill(pid,SIGUSR2);
            j++;
            usleep(50);
        }
        i++;
        free(temp);
    }
    ft_send_term(pid);
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	char	*string;

	if (argc != 3)
		exit (0);
	i = 0;
	pid = ft_atoi(argv[1]);
	string = argv[2];
	ft_send_signal(pid, string);
}
