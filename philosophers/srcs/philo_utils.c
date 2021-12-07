/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:06:11 by jkosiara          #+#    #+#             */
/*   Updated: 2021/12/07 15:06:12 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(int time)
{
	long	start;

	start = ft_time();
	while (ft_time() < start + time)
		usleep(10);
}

int	is_dead(t_philo *philo)
{
	long	now;

	now = elapsed_time(philo->main->start_time);
	if ((philo->main->t_die < (now - philo->start_eat))
		&& philo->status != EATING)
	{
		philo->status = DEAD;
		select_message(philo);
		pthread_mutex_lock(&philo->main->death);
		philo->main->dead_found = 1;
		pthread_mutex_unlock(&philo->main->death);
		return (1);
	}
	usleep (100);
	return (0);
}

int	is_alive(t_philo *philo)
{
	if (philo->status != DEAD && !philo->main->dead_found)
		return (1);
	return (0);
}

int	is_hungry(t_philo *philo)
{
	if (philo->meal_taken < philo->main->nb_meal)
		return (1);
	return (0);
}

int	has_eaten_enough(t_philo *philo)
{
	if (philo->meal_taken == philo->main->nb_meal)
		return (1);
	return (0);
}
