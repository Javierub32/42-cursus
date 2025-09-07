/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_input
{
	int		argc;
	char	**argv;
	char	**env;
	int		num_cmds;

}	t_input;

typedef struct s_release
{
	int		**pipes;
	pid_t	*pids;
	int		num_pipes;
}	t_release;

# define ERR_NO_FILE		2
# define ERR_IO				5
# define ERR_PERMISSION		13
# define ERR_INVALID_ARG	22

# define ERR_NO_PROCESS		3
# define ERR_INTERRUPTED	4
# define ERR_NO_CHILD		10
# define ERR_NO_RESOURCE	11
# define ERR_BROKEN_PIPE	32

void	check_initial_errors(int argc, char **argv);
void	print_error(int error_code);

void	free_pipes(int **pipes, int num_pipes);
int		**create_pipes(int num_pipes);
void	close_all_pipes(int **pipes, int num_pipes);
void	wait_all_processes(pid_t *pids, int num_processes);

void	handle_child_process(t_input data, int cmd_index, t_release *release);
void	execute_command(char *argv, char **envp, t_release *release);
#endif
