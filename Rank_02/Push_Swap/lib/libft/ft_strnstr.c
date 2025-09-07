/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:36:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:36:44 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j]
				&& haystack[i + j] && i + j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *) haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
