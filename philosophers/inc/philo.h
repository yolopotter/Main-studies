/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:19 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/18 13:51:00 by vlopatin         ###   ########.fr       */
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

void	exit_error(int error, const char *msg);

#endif
