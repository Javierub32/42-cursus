/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid_left_child;
	int	pid_right_child;

	check_initial_errors(argc, argv);
	if (pipe(fd) == -1)
		print_error(ERR_BROKEN_PIPE);
	pid_left_child = fork();
	if (pid_left_child < 0)
		print_error(ERR_NO_CHILD);
	else if (pid_left_child == 0)
	{
		handle_left_pipe(argv, envp, fd);
	}
	else
	{
		pid_right_child = fork();
		if (pid_right_child < 0)
			print_error(ERR_NO_CHILD);
		else if (pid_right_child == 0)
			handle_right_pipe(argv, envp, fd);
		else
			wait_process(fd, pid_left_child, pid_right_child);
	}
	return (0);
}
