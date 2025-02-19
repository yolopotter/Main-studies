/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:19 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/19 11:24:54 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> //NULL
# include <stdio.h> //printf
# include <sys/time.h> //gettimeofday
# include <pthread.h> //threads

# define ARGS1	"Incorrect amount of arguments\n"
# define ARGS2	"Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] "
# define ARGS3	"[time_to_sleep] ([number_of_times_each_philosopher_must_eat])\n"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

typedef struct s_thread_data
{
	int id;
	int *should_continue;
	int starting_process;
	pthread_mutex_t *eating_mutex;
}	t_thread_data;

void	exit_error(int error, const char *msg);

#endif
