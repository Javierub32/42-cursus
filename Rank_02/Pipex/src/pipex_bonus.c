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

static void	inicialize_struct(t_release *rel, int **pips, pid_t *pids, int npip)
{
	rel->pipes = pips;
	rel->pids = pids;
	rel->num_pipes = npip;
}

static void	create_child_process(t_input data, t_release *release, int i)
{
	release->pids[i] = fork();
	if (release->pids[i] == -1)
		print_error(ERR_NO_CHILD);
	if (release->pids[i] == 0)
		handle_child_process(data, i, release);
}

int	main(int argc, char **argv, char **envp)
{
	int			**pipes;
	pid_t		*pids;
	int			i;
	t_input		input_data;
	t_release	release;

	check_initial_errors(argc, argv);
	input_data = (t_input){argc, argv, envp, argc - 3};
	pipes = create_pipes(input_data.num_cmds - 1);
	pids = malloc(sizeof(pid_t) * input_data.num_cmds);
	if (!pipes || !pids)
		print_error(ERR_NO_RESOURCE);
	inicialize_struct(&release, pipes, pids, input_data.num_cmds - 1);
	i = 0;
	while (i < input_data.num_cmds)
	{
		create_child_process(input_data, &release, i);
		i++;
	}
	close_all_pipes(pipes, input_data.num_cmds - 1);
	wait_all_processes(pids, input_data.num_cmds);
	return (free_pipes(pipes, input_data.num_cmds - 1), free(pids), 0);
}
