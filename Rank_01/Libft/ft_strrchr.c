/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:35:01 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:35:02 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	l;

	l = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (l == s[i])
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
