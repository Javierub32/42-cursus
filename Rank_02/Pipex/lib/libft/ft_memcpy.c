/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:12 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:32:20 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr_src = (unsigned char *) src;
	ptr_dst = (unsigned char *) dst;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
