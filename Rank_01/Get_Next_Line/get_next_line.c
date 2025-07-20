/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:28:15 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/01 11:28:39 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*tmp;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, &rest, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	tmp = line;
	line = extract_line(tmp);
	rest = extract_rest(tmp);
	free(tmp);
	return (line);
}

char	*extract_rest(char *str)
{
	char	*newline;
	char	*new_rest;

	newline = ft_strchr(str, '\n');
	if (!newline)
		return (NULL);
	newline++;
	new_rest = ft_strdup(newline);
	return (new_rest);
}

char	*extract_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	ft_strncpy(line, str, i + 1);
	line[i + 1] = '\0';
	return (line);
}

char	*read_line(int fd, char **rest, char *buffer)
{
	ssize_t	bytes_read;
	char	*old;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(*rest), *rest = NULL, NULL);
		buffer[bytes_read] = '\0';
		if (!*rest)
			*rest = ft_strdup("");
		old = *rest;
		*rest = ft_strjoin(old, buffer);
		free(old);
		if (ft_strchr(buffer, '\n') || bytes_read == 0)
			break ;
	}
	if (!*rest || **rest == '\0')
		return (free(*rest), *rest = NULL, NULL);
	return (*rest);
}
