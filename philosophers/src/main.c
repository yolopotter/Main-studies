/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:41:06 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/21 14:51:47 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	msg_broadcast(t_philo *philo, char *msg)
{
	size_t timestamp;

	pthread_mutex_lock(philo->msg_lock);
	timestamp = (get_current_time() - philo->start);
	printf("%li ms %i %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(philo->msg_lock);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	msg_broadcast(philo, FORK);
	pthread_mutex_lock(philo->r_fork);
	msg_broadcast(philo, FORK);
	msg_broadcast(philo, EATING);
	ft_asleep(1100);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
 
void	sleeping(t_philo *philo)
{
	msg_broadcast(philo, SLEEPING);
	ft_asleep(800);
}

void	thinking(t_philo *philo)
{
	msg_broadcast(philo, THINKING);
}

void	*thread_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	int current_process = philo->starting_process;
	while (*(philo->should_continue) == 1)
	{
		if (current_process == 1)
		{
			eating(philo);
			current_process = 2;
		}
		if (current_process == 2)
		{
			sleeping(philo);
			current_process = 3;
		}
		if (current_process == 3)
		{
			thinking(philo);
			current_process = 1;
		}
	}
	return NULL;
}

// void	*monitor(void *ptr)
// {
// 	t_philo *observer;

// 	observer = (t_philo *)ptr;
// }

void	init_time_and_send(pthread_t *threads, t_philo *philo)
{
	int	i;

	i = 0;
	philo[i].start = get_current_time();
	i++;
	while (i < 3)
	{
		philo[i].start = philo[0].start;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		pthread_create(&threads[i], NULL, thread_routine, &philo[i]);
		i++;
	}
}

void	init_philos(t_philo *philo, int amount, pthread_mutex_t *forks, int *should_continue, pthread_mutex_t *msg_lock)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		philo[i].id = i;
		philo[i].should_continue = should_continue;
		philo[i].l_fork = &forks[i];
		if (i != 0)
			philo[i].r_fork = &forks[i - 1];
		else
			philo[i].r_fork = &forks[amount - 1];
		philo[i].msg_lock = msg_lock;
		philo[i].starting_process = i + 1;
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	destroy_forks(pthread_mutex_t *forks, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	init_threads(int amount)
{
	t_philo			philo[amount];
	pthread_t		threads[amount];
	pthread_mutex_t	forks[amount];
	t_global_data	globals;

	init_forks(forks, amount);
	pthread_mutex_init(&globals.msg_lock, NULL);

	int should_continue = 1;
	init_philos(philo, amount, forks, &should_continue, &globals.msg_lock);
	// pthread_t observer;

	init_time_and_send(threads, philo);

	// pthread_create(&observer, NULL, &monitor, &philo[3]);

	sleep(10);

	should_continue = 0;
	int i = 0;
	while (i < amount)
		pthread_join(threads[i++], NULL);

	destroy_forks(forks, amount);
	pthread_mutex_destroy(&globals.msg_lock);
	return 0;
}

int	main(int ac, char **av)
{
	// if (ac != 5 && ac != 6)
		// exit_error(1, NULL);
	(void)ac;
	(void)av;

	init_threads(3);

	return (0);
}

