/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(int error_code)
{
	if (error_code == ERR_NO_FILE)
		write(2, "Error: No such file or directory.\n", 34);
	else if (error_code == ERR_IO)
		write(2, "Error: Input/output error.\n", 27);
	else if (error_code == ERR_PERMISSION)
		write(2, "Error: Permission denied.\n", 26);
	else if (error_code == ERR_INVALID_ARG)
		write(2, "Error: Invalid arguments.\n", 26);
	else if (error_code == ERR_INTERRUPTED)
		write(2, "Error: Interrupted system call.\n", 32);
	else if (error_code == ERR_NO_PROCESS)
		write(2, "Error: No such process!\n", 24);
	else if (error_code == ERR_NO_CHILD)
		write(2, "Error: No child processes!\n", 27);
	else if (error_code == ERR_NO_RESOURCE)
		write(2, "Error: Resource temporarily unavailable!\n", 41);
	else if (error_code == ERR_BROKEN_PIPE)
		write(2, "Error: Broken pipe. Pipe write error!\n", 38);
	else
		write(2, "Error: Unknown error occurred.\n", 31);
	exit(1);
}

void	check_initial_errors(int argc, char **argv)
{
	int	output_file;

	if (argc != 5)
		print_error(ERR_INVALID_ARG);
	else if (access(argv[1], F_OK) != 0)
		print_error(ERR_NO_FILE);
	else if (access(argv[1], R_OK) != 0)
		print_error(ERR_PERMISSION);
	else if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
		print_error(ERR_INVALID_ARG);
	else if ((access(argv[4], F_OK) != 0))
	{
		output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 511);
		if (output_file == -1)
			print_error(ERR_NO_FILE);
		close(output_file);
		if (access(argv[4], W_OK) != 0)
			print_error(ERR_PERMISSION);
	}
	return ;
}
