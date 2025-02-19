/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:41:06 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/19 16:06:19 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>

void	eating(t_thread_data *data)
{
	long int timestamp;

	pthread_mutex_lock(data->eating_mutex);
	if (data->start.tv_usec == 0)
		gettimeofday(&(data->start), NULL);
	gettimeofday(&(data->current), NULL);
	if (data->current.tv_usec < data->start.tv_usec)
		data->current.tv_usec += 1000000;
	// printf("time current usec (eating): %li ms\n", data->current.tv_usec / 1000);
	// printf("time start usec (eating): %li ms\n", data->start.tv_usec / 1000);
	timestamp = (data->current.tv_sec - data->start.tv_sec) * 1000 + (data->current.tv_usec - data->start.tv_usec) / 1000;
	printf(GREEN "%li ms %i started Eating\n" RESET, timestamp, data->id);
	usleep (1100000);
	pthread_mutex_unlock(data->eating_mutex);
	printf(BLUE "%li ms %i finished Eating\n" RESET, timestamp, data->id);
}

void	sleeping(t_thread_data *data)
{
	long int timestamp;

	if (data->start.tv_usec == 0)
		gettimeofday(&(data->start), NULL);
	gettimeofday(&(data->current), NULL);
	if (data->current.tv_usec < data->start.tv_usec)
		data->current.tv_usec += 1000000;
	// printf("time current usec (sleeping): %li ms\n", data->current.tv_usec / 1000);
	// printf("time start usec (sleeping): %li ms\n", data->start.tv_usec / 1000);
	// printf("time current (sleeping): %li\n", data->current.tv_sec);
	timestamp = (data->current.tv_sec - data->start.tv_sec) * 1000;
	printf("%li ms %i is sleeping\n", timestamp, data->id);
	usleep (800000);
}

void	thinking(t_thread_data *data)
{
	long int timestamp;

	if (data->start.tv_usec == 0)
		gettimeofday(&(data->start), NULL);
	gettimeofday(&(data->current), NULL);
	if (data->current.tv_usec < data->start.tv_usec)
		data->current.tv_usec += 1000000;
	// printf("time current usec (thinking): %li ms\n", data->current.tv_usec / 1000);
	// printf("time start usec (thinking): %li ms\n", data->start.tv_usec / 1000);
	// printf("time current (thinking): %li\n", data->current.tv_sec);
	timestamp = (data->current.tv_sec - data->start.tv_sec) * 1000;
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

void	*monitor(void *ptr)
{
	t_thread_data *observer;

	observer = (t_thread_data *)ptr;
}

int	init_threads()
{
	t_thread_data thread_data[3];

	pthread_mutex_t eating_mutex;
	if (pthread_mutex_init(&eating_mutex, NULL) != 0)
	{
		perror("pthread_mutex_init");
		return 1;
	}
	int should_continue = 1;

	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	pthread_t observer;

	thread_data[0].id = 1;
	thread_data[1].id = 2;
	thread_data[2].id = 3;

	thread_data[0].should_continue = &should_continue;
	thread_data[1].should_continue = &should_continue;
	thread_data[2].should_continue = &should_continue;

	thread_data[0].eating_mutex = &eating_mutex;
	thread_data[1].eating_mutex = &eating_mutex;
	thread_data[2].eating_mutex = &eating_mutex;

	thread_data[0].starting_process = 1;
	thread_data[1].starting_process = 2;
	thread_data[2].starting_process = 3;

	thread_data[0].start.tv_usec = 0;
	thread_data[1].start.tv_usec = 0;
	thread_data[2].start.tv_usec = 0;

	pthread_create(&thread1, NULL, thread_routine, &thread_data[0]);
	pthread_create(&thread2, NULL, thread_routine, &thread_data[1]);
	pthread_create(&thread3, NULL, thread_routine, &thread_data[2]);

	pthread_create(&observer, NULL, &monitor, &thread_data[3]);

	sleep(10);

	should_continue = 0;
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	return 0;
}

int	main(int ac, char **av)
{
	// if (ac != 5 && ac != 6)
		// exit_error(1, NULL);
	(void)ac;
	(void)av;

	// pthread_t threads[3];


	struct timeval start;
	gettimeofday(&start, NULL);

	init_threads();

	return (0);
}

