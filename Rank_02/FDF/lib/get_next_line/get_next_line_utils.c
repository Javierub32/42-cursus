/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:27:59 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/01 11:28:02 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, size_t tam)
{
	size_t	i;

	i = 0;
	while (i < tam && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < tam)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	size_s1;
	size_t	size_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size = size_s1 + size_s2;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, size_s1);
	ft_strncpy(str + size_s1, s2, size_s2);
	str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	l;

	l = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == l)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == l)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dup = (char *)malloc((i + 1) * 1);
	if (dup == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
