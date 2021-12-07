/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:05:36 by jkosiara          #+#    #+#             */
/*   Updated: 2021/12/07 15:05:37 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	lock_forks(t_philo *philo)
{
	philo->status = TAKE_FORK;
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		select_message(philo);
		if (philo->main->nb_philo == 1)
			while (philo->status != DEAD)
				;
		else
		{
			pthread_mutex_lock(philo->left_fork);
			select_message(philo);
		}
	}	
	else
	{
		pthread_mutex_lock(philo->right_fork);
		select_message(philo);
		pthread_mutex_lock(philo->left_fork);
		select_message(philo);
	}
}

static	void	unlock_forks(t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_unlock(philo->right_fork);
	if (philo->main->nb_philo == 1)
		return ;
	pthread_mutex_unlock(philo->left_fork);
	select_message(philo);
	ft_usleep(philo->main->t_sleep);
}

static	void	eat(t_philo *philo)
{
	philo->status = EATING;
	philo->start_eat = elapsed_time(philo->main->start_time);
	select_message(philo);
	ft_usleep(philo->main->t_eat);
	philo->meal_taken++;
	if (philo->main->nb_meal > 0 && has_eaten_enough(philo))
	{
		pthread_mutex_lock(&philo->main->finished_meal);
		philo->main->nb_finished_meal = philo->main->nb_finished_meal + 1;
		pthread_mutex_unlock(&philo->main->finished_meal);
	}
}

static void	think(t_philo *philo)
{
	philo->status = THINKING;
	select_message(philo);
}

void	philo_cycle(t_philo *philo)
{
	lock_forks(philo);
	eat(philo);
	unlock_forks(philo);
	think(philo);
	usleep(100);
}
