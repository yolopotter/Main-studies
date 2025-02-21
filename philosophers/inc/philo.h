/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:19 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/21 14:39:15 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> //NULL
# include <stdio.h> //printf
# include <sys/time.h> //gettimeofday
# include <pthread.h> //threads
# include <unistd.h> //usleep, write

# define ARGS1		"Incorrect amount of arguments\n"
# define ARGS2		"Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] "
# define ARGS3		"[time_to_sleep] ([number_of_times_each_philosopher_must_eat])\n"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define FORK		"has taken a fork"
# define DEATH		"died"

typedef struct s_philo
{
	int id;
	int *should_continue;
	int starting_process;
	size_t start;
	size_t current;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *msg_lock;
}	t_philo;

typedef struct s_global_data
{
	pthread_mutex_t msg_lock;
}	t_global_data;


//exit
void	exit_error(int error, const char *msg);

//utils
size_t	get_current_time();
void	ft_asleep(size_t sleep_in_ms);

#endif
