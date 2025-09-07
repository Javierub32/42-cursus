/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	**create_pipes(int num_pipes)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * num_pipes);
	if (!pipes)
		print_error(ERR_NO_RESOURCE);
	i = 0;
	while (i < num_pipes)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
			print_error(ERR_NO_RESOURCE);
		if (pipe(pipes[i]) == -1)
			print_error(ERR_BROKEN_PIPE);
		i++;
	}
	return (pipes);
}

void	close_all_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	wait_all_processes(pid_t *pids, int num_processes)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_processes)
	{
		if (waitpid(pids[i], &status, 0) == -1)
			print_error(ERR_INTERRUPTED);
		i++;
	}
}

void	free_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}
