
#include "../includes/pipex.h"

void	print_error(int error_code)
{
	if (error_code == ERR_NO_FILE)
		ft_printf("Error: No such file or directory.\n");
	else if (error_code == ERR_IO)
		ft_printf("Error: Input/output error.\n");
	else if (error_code == ERR_PERMISSION)
		ft_printf("Error: Permission denied.\n");
	else if (error_code == ERR_INVALID_ARG)
		ft_printf("Error: Invalid arguments.\n");
	else if (error_code == ERR_INTERRUPTED)
		ft_printf("Error: Interrupted system call.\n");
	else if (error_code == ERR_NO_PROCESS)
		ft_printf("Error: No such process!\n");
	else if (error_code == ERR_NO_CHILD)
		ft_printf("Error: No child processes!\n");
	else if (error_code == ERR_NO_RESOURCE)
		ft_printf("Error: Resource temporarily unavailable!\n");
	else if (error_code == ERR_BROKEN_PIPE)
		ft_printf("Error: Broken pipe. Pipe write error!\n");
	else
		ft_printf("Error: Unknown error occurred.\n");
	exit(1);
}

void	check_errors(int argc, char **argv)
{
	int	output_file;

	if (argc != 5)
		print_error(ERR_INVALID_ARG);
	else if (access(argv[1], F_OK) != 0)
		print_error(ERR_NO_FILE);
	else if (access(argv[1], R_OK) != 0)
		print_error(ERR_PERMISSION);
	else if ((access(argv[4], F_OK) != 0))
	{
		output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (output_file == -1)
			print_error(ERR_NO_FILE);
		else
			// If the file does not exist, it will be created with write permissions.
			ft_printf("Output file created successfully.\n");
		close(output_file);
		if (access(argv[4], W_OK) != 0)
			print_error(ERR_PERMISSION);
	}
	return ;
}