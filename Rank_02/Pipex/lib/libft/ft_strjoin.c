/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:36:21 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:36:56 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strncpy(char *dest, const char *src, size_t tam)
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
