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
void	wait_process(int *fd, pid_t pid1, pid_t pid2);
void	handle_left_pipe(char **argv, char **envp, int *fd);
void	handle_right_pipe(char **argv, char **envp, int *fd);

void	execute_command(char *argv, char **envp);
#endif
