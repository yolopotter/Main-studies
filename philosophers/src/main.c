/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:41:06 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/18 14:49:53 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>

int stop_thread1 = 0;

void	*process1(void *arg)
{
	int *value = (int *)arg;
	printf("Hello from process1, I am thread %i\n", *value);
	return NULL;
}

void	*process2(void *arg)
{
	int *value = (int *)arg;
	printf("Hello from process2, I am thread %i\n", *value);
	return NULL;
}

void	*process3(void *arg)
{
	int *value = (int *)arg;
	printf("Hello from process3, I am thread %i\n", *value);
	return NULL;
}

int	main(int ac, char **av)
{
	// if (ac != 5 && ac != 6)
		// exit_error(1, NULL);
	av = NULL;
	ac = 0;

	int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	int nb1 = 1;
	int nb2 = 2;
	int nb3 = 3;

	pthread_create(&thread1, NULL, process1, (void *)&nb1);
	pthread_create(&thread2, NULL, process2, (void *)&nb2);
	pthread_create(&thread3, NULL, process3, (void *)&nb3);

	pthread_join(thread2, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	return (0);
}
