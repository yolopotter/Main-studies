/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:27:28 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/13 16:02:16 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <errno.h>

// 13:	command not found error
// 14:	file opening error
// 15:	command is NULL error

void	print_error(int error, char ***arr1, const char *msg)
{
	ft_putstr_fd(PIPEX, 2);
	if (error == 13)
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putendl_fd((*arr1)[0], 2);
	}
	if (error == 14)
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
	if (error == 15)
		ft_putendl_fd(PATH1, 2);
}

// 1:	amount of argument error
// 2:	pipe or fork creation error
// 3:	command not found error
// 4:	file opening error and malloc error
// 5:	command is NULL error
// 6:	execve failure

static void	exit_error_1(int error, char ***arr1, const char *msg)
{
	ft_putstr_fd(PIPEX, 2);
	if (error == 1)
	{
		ft_putendl_fd(AC1, 2);
		ft_putendl_fd((char *)msg, 2);
	}
	if (error == 2)
		perror((char *)msg);
	if (error == 3)
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putendl_fd((*arr1)[0], 2);
		ft_free_split(*arr1);
		arr1 = NULL;
		exit (127);
	}
}

static void	exit_error_2(int error, const char *msg)
{
	ft_putstr_fd(PIPEX, 2);
	if (error == 4)
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
	if (error == 5)
	{
		ft_putendl_fd(PATH1, 2);
		exit(127);
	}
}

void	exit_error_3(int error, char ***arr1, t_side *left, t_side *right)
{
	ft_putstr_fd(PIPEX, 2);
	if (error == 6)
	{
		ft_putstr_fd((*arr1)[0], 2);
		ft_putstr_fd(": ", 2);
		if (ft_strrchr((*arr1)[0], '/') ==
			&((*arr1)[0][ft_strlen((*arr1)[0]) - 1]))
		{
			close_free_left(left);
			close_free_right(right);
			ft_putendl_fd(PATH1, 2);
			exit(126);
		}
		else
		{
			close_free_left(left);
			close_free_right(right);
			ft_putendl_fd(PATH, 2);
			exit(127);
		}
	}
}

void	exit_error(int error, char ***arr1, const char *msg)
{
	if (error >= 1 && error <= 3)
		exit_error_1(error, arr1, msg);
	if (error >= 4 && error <= 5)
		exit_error_2(error, msg);
	exit(1);
}
