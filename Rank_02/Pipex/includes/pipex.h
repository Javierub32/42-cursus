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

# define ERR_NO_FILE        2   // ENOENT: No such file or directory
# define ERR_IO             5   // EIO: Input/output error
# define ERR_PERMISSION     13  // EACCES: Permission denied
# define ERR_INVALID_ARG    22  // EINVAL: Invalid argument

// Errores relacionados con procesos
# define ERR_NO_PROCESS     3   // ESRCH: No such process
# define ERR_INTERRUPTED    4   // EINTR: Interrupted system call
# define ERR_NO_CHILD       10  // ECHILD: No child processes
# define ERR_NO_RESOURCE    11  // EAGAIN: Resource temporarily unavailable
# define ERR_BROKEN_PIPE    32  // EPIPE: Broken pipe

void	check_errors(int argc, char **argv);
void	print_error(int error_code);

#endif
