/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:30:57 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/07 18:30:59 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	setup_input_file(char *filename);
static void	setup_output_file(char *filename);
static void	setup_pipe_input(int *pipe_fd);
static void	setup_pipe_output(int *pipe_fd);

void	handle_child_process(t_input data, int cmd_index, t_release *release)
{
	if (cmd_index == 0)
		setup_input_file(data.argv[1]);
	else
		setup_pipe_input(release->pipes[cmd_index - 1]);
	if (cmd_index == data.num_cmds - 1)
		setup_output_file(data.argv[cmd_index + 3]);
	else
		setup_pipe_output(release->pipes[cmd_index]);
	close_all_pipes(release->pipes, data.num_cmds - 1);
	execute_command(data.argv[cmd_index + 2], data.env, release);
}

static void	setup_input_file(char *filename)
{
	int	input_file;

	input_file = open(filename, O_RDONLY);
	if (input_file == -1)
		print_error(ERR_NO_FILE);
	if (dup2(input_file, STDIN_FILENO) == -1)
	{
		close(input_file);
		print_error(ERR_INTERRUPTED);
	}
	close(input_file);
}

static void	setup_output_file(char *filename)
{
	int	output_file;

	output_file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1)
		print_error(ERR_NO_FILE);
	if (dup2(output_file, STDOUT_FILENO) == -1)
	{
		close(output_file);
		print_error(ERR_INTERRUPTED);
	}
	close(output_file);
}

static void	setup_pipe_input(int *pipe_fd)
{
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		print_error(ERR_INTERRUPTED);
}

static void	setup_pipe_output(int *pipe_fd)
{
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		print_error(ERR_INTERRUPTED);
}
