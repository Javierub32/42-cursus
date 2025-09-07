/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:36:14 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:36:15 by jurbanej         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_strncpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}
