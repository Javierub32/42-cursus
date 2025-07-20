/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:12 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:32:37 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	rev_copy(unsigned char *ptr_dst, unsigned char *ptr_src, size_t n)
{
	while (n > 0)
	{
		n--;
		ptr_dst[n] = ptr_src[n];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr_src = (unsigned char *) src;
	ptr_dst = (unsigned char *) dst;
	i = 0;
	if (ptr_dst > ptr_src)
	{
		rev_copy(ptr_dst, ptr_src, n);
	}
	else
	{
		while (i < n)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
