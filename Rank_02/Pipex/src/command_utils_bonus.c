/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

static char	**search_posible_paths(char **envp)
{
	int		i;
	char	**posible_paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 3) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		print_error(ERR_NO_FILE);
	posible_paths = ft_split(envp[i] + 5, ':');
	return (posible_paths);
}

static char	*get_path(char *command, char **envp)
{
	char	*route;
	char	*path;
	char	**posible_paths;
	int		i;

	i = 0;
	posible_paths = search_posible_paths(envp);
	while (posible_paths[i])
	{
		route = ft_strjoin("/", command);
		path = ft_strjoin(posible_paths[i], route);
		free(route);
		if (access(path, F_OK) == 0)
		{
			free_paths(posible_paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_paths(posible_paths);
	return (NULL);
}

void	execute_command(char *argv, char **envp, t_release *release)
{
	char	*path;
	char	**commands;

	commands = ft_split(argv, ' ');
	path = get_path(commands[0], envp);
	if (!path)
	{
		free_paths(commands);
		free_pipes(release->pipes, release->num_pipes);
		free(release->pids);
		print_error(ERR_NO_FILE);
	}
	if (execve(path, commands, envp) == -1)
	{
		free(path);
		free_paths(commands);
		print_error(ERR_INTERRUPTED);
	}
	free(path);
	free_paths(commands);
}
