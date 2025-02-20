/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:32:58 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/20 13:33:17 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

size_t	get_current_time()
{
	struct timeval time_now;

	if (gettimeofday(&time_now, NULL) == -1)
		write(2, "Error gettimeofday()\n", 21);
	return (time_now.tv_sec * 1000 + time_now.tv_usec / 1000);
}

void	ft_asleep(size_t sleep_in_ms)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < sleep_in_ms)
		usleep(300);
}
