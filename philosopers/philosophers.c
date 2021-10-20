/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:19:46 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/20 17:08:06 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_parsing(t_info *info, int argc, char *argv[])
{
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
}

static int ft_check_arg(t_info *info, int argc)
{
	if (argc==[6] && info->number_of_philosophers <= 0)
		return ("wrong number of philosophers, retry.");
	if (info->time_to_die <= 0)
		return ("wrong time to die, retry.");
	if (info->time_to_eat <=0)
		return ("wrong time to eat, retry.");
	if (info->time_to_sleep <= 0)
		return ("wrong time to sleep, retry.");
		return(SUCCESS);
}

void* routine(){
	printf("Test from threads");
}

int main(int argc, char *arvg[])
{
	t_info *info;
	info = ft_parsing(&info, argc, argv);
	
	return 0;
}