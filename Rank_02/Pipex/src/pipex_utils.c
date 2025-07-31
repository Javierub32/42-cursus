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

void	handle_left_pipe(char **argv, char **envp, int *fd)
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY, 0777);
	if (input_file == -1)
		print_error(ERR_NO_FILE);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd[1]);
		print_error(ERR_INTERRUPTED);
	}
	if (dup2(input_file, STDIN_FILENO) == -1)
	{
		close(input_file);
		print_error(ERR_INTERRUPTED);
	}
	close(fd[0]);
	close(input_file);
	execute_command(argv[2], envp);
}

void	handle_right_pipe(char **argv, char **envp, int *fd)
{
	int	output_file;

	output_file = open(argv[4], O_WRONLY | O_TRUNC, 0777);
	if (output_file == -1)
		print_error(ERR_NO_FILE);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		print_error(ERR_INTERRUPTED);
	}
	if (dup2(output_file, STDOUT_FILENO) == -1)
	{
		close(output_file);
		print_error(ERR_INTERRUPTED);
	}
	close(fd[0]);
	close(fd[1]);
	close(output_file);
	execute_command(argv[3], envp);
}

void	wait_process(int *fd, pid_t pid1, pid_t pid2)
{
	close(fd[0]);
	close(fd[1]);
	if (waitpid(pid1, NULL, 0) == -1)
		print_error(ERR_INTERRUPTED);
	if (waitpid(pid2, NULL, 0) == -1)
		print_error(ERR_INTERRUPTED);
}
