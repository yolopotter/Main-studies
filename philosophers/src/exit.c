/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:43:47 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/18 12:11:32 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exit_error(int error, const char *msg)
{
	if (error == 1)
		printf(ARGS1 ARGS2 ARGS3);
	msg = NULL;
}
