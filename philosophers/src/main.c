/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:41:06 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/20 16:07:00 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eating(t_thread_data *data)
{
	long int timestamp;

	pthread_mutex_lock(data->eating_lock);
	data->current = get_current_time();
	// printf("time current usec (eating): %li ms\n", data->current);
	// printf("time start usec (eating): %li ms\n", data->start);
	timestamp = (data->current - data->start);
	printf(GREEN "%li ms %i started Eating\n" RESET, timestamp, data->id);
	ft_asleep(1100);
	pthread_mutex_unlock(data->eating_lock);
	printf(BLUE "%li ms %i finished Eating\n" RESET, timestamp, data->id);
}

void	sleeping(t_thread_data *data)
{
	long int timestamp;

	data->current = get_current_time();
	timestamp = (data->current - data->start);
	printf("%li ms %i is sleeping\n", timestamp, data->id);
	ft_asleep(800);
}

void	thinking(t_thread_data *data)
{
	long int timestamp;

	data->current = get_current_time();
	timestamp = (data->current - data->start);
	printf("%li ms %i is thinking\n", timestamp, data->id);
}

void	*thread_routine(void *arg)
{
	t_thread_data *data = (t_thread_data *)arg;
	int current_process = data->starting_process;
	while (*(data->should_continue) == 1)
	{
		if (current_process == 1)
		{
			eating(data);
			current_process = 2;
		}
		if (current_process == 2)
		{
			sleeping(data);
			current_process = 3;
		}
		if (current_process == 3)
		{
			thinking(data);
			current_process = 1;
		}
	}
	return NULL;
}

// void	*monitor(void *ptr)
// {
// 	t_thread_data *observer;

// 	observer = (t_thread_data *)ptr;
// }

void	init_time_and_send(pthread_t *threads, t_thread_data *thread_data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		thread_data[i].start = get_current_time();
		pthread_create(&threads[i], NULL, thread_routine, &thread_data[i]);
		i++;
	}
}

void	init_philos(t_thread_data *thread_data, int amount, pthread_mutex_t *eating_lock, int *should_continue)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		thread_data[i].id = i;
		thread_data[i].should_continue = should_continue;
		thread_data[i].eating_lock = eating_lock;
		thread_data[i].starting_process = i + 1;
		i++;
	}
}

int	init_threads(int amount)
{
	t_thread_data	thread_data[amount];
	pthread_t		threads[amount];

	pthread_mutex_t eating_lock;
	if (pthread_mutex_init(&eating_lock, NULL) != 0)
	{
		perror("pthread_mutex_init");
		return 1;
	}
	int should_continue = 1;
	init_philos(thread_data, amount, &eating_lock, &should_continue);
	// pthread_t observer;
	int i = 0;


	init_time_and_send(threads, thread_data);
	// pthread_create(&thread1, NULL, thread_routine, &thread_data[0]);
	// pthread_create(&thread2, NULL, thread_routine, &thread_data[1]);
	// pthread_create(&thread3, NULL, thread_routine, &thread_data[2]);

	// pthread_create(&observer, NULL, &monitor, &thread_data[3]);

	sleep(10);

	should_continue = 0;
	i = 0;
	while (i < amount)
		pthread_join(threads[i++], NULL);

	pthread_mutex_destroy(&eating_lock);
	return 0;
}

int	main(int ac, char **av)
{
	// if (ac != 5 && ac != 6)
		// exit_error(1, NULL);
	(void)ac;
	(void)av;

	struct timeval start;
	gettimeofday(&start, NULL);

	init_threads(3);

	return (0);
}

