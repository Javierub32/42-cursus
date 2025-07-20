/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:33:48 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:33:57 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
