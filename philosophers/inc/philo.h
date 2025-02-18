/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:39:19 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/17 14:48:18 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ARGS1	"Incorrect amount of arguments"
# define ARGS2	"Usage: ./philo number_of_philosophers time_to_die time_to_eat
# define ARGS3	"time_to_sleep (number_of_times_each_philosopher_must_eat)"

void	exit_error(const char *msg);

#endif
