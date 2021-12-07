/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:06:15 by jkosiara          #+#    #+#             */
/*   Updated: 2021/12/07 15:06:16 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*death_watch(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->main->nb_meal > 0)
	{
		while (is_alive(philo) && is_hungry(philo))
			if (is_dead(philo))
				break ;
	}
	else
	{
		while (is_alive(philo))
			if (is_dead(philo))
				break ;
	}
	return ((void *) 0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death;

	philo = (t_philo *)arg;
	if (pthread_create(&death, NULL, &death_watch, philo) != 0)
	{
		free_all(philo->main);
		return ((void *)0);
	}
	pthread_detach(death);
	if (philo->main->nb_meal > 0)
		while (is_alive(philo) && is_hungry(philo))
			philo_cycle(philo);
	else
		while (is_alive(philo))
			philo_cycle(philo);
	return ((void *) 0);
}

void	launch_threads(t_main *main)
{
	int			i;
	pthread_t	main_thread;
	t_philo		*philo;

	i = -1;
	main->start_time = ft_time();
	while (++i < main->nb_philo)
	{	
		philo = &main->philo[i];
		if (pthread_create(&main_thread, NULL, &routine, (void *)philo) != 0)
			return (free_all(main));
		pthread_detach(main_thread);
		usleep(100);
	}
}

void	launch_monitoring(t_main *main)
{
	if (main->nb_meal > 0)
		meal_and_death_monitor(main);
	else
		death_monitor(main);
}

int	main(int argc, char **argv)
{
	t_main	main;

	printf("\033[0;32m\n\t 42_PHILOSOPHERS \033[0m\n\n");
	if (argc >= 5 && argc <= 6)
	{
		if (!init(&main, argc, argv))
		{
			printf("Invalid arguments\n");
			return (1);
		}
		launch_threads(&main);
		launch_monitoring(&main);
		free_all(&main);
	}
	else
	{
		printf("Invalid number of parameters\n");
		return (1);
	}
	return (0);
}
