/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:35:07 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/10 19:27:33 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	close_fds(int fd1, int *fd2, int *fd3, int amount)
{
	int	i;

	i = 0;
	while (i < amount && fd3)
	{
		if (fd3[i] != -1)
			close (fd3[i]);
		fd3[i] = -1;
		i++;
	}
	i = 0;
	while (i < amount && fd2)
	{
		if (fd2[i] != -1)
			close (fd2[i]);
		fd2[i] = -1;
		i++;
	}
	if (fd1 != -1)
	{
		close(fd1);
		fd1 = -1;
	}
}

void	close_free_left(t_side	*left)
{
	close_fds(left->fd, NULL, NULL, 0);
	left->fd = -1;
	ft_free_split(left->cmd);
	left->cmd = NULL;
	free(left->path);
	left->path = NULL;
}

void	close_free_right(t_side	*right)
{
	close_fds(right->fd, NULL, NULL, 0);
	right->fd = -1;
	ft_free_split(right->cmd);
	right->cmd = NULL;
	free(right->path);
	right->path = NULL;
}
