/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:14:57 by jkosiara          #+#    #+#             */
/*   Updated: 2021/10/20 16:50:18 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
#include <sys/time.h>

/* pthread_mutex_t è una struttura che contiene:
- Nome del mutex
- Proprietario
- Contatore
- Struttura associata al mutex
- La coda dei processi sospesi in attesa che mutex sia libero.
… e simili */

typedef struct s_philo{
	
}				t_philo;

typedef struct s_info{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
}				t_info;

static void	ft_parsing(t_info *info, int argc, char *argv[])

#endif