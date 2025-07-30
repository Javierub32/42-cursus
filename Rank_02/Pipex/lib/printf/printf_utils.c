/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:55:06 by jurbanej          #+#    #+#             */
/*   Updated: 2025/06/18 11:55:08 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_base_len(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

void	printf_putchar(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*count = -1;
	else
		(*count)++;
}

void	printf_putstr(char *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		printf_putchar(str[i], count);
		i++;
	}
}

void	printf_putpointer(unsigned long long ptr, int *result)
{
	if (ptr == 0)
	{
		printf_putstr("(nil)", result);
		return ;
	}
	printf_putstr("0x", result);
	if (ptr >= 16)
	{
		printf_putnbr_based((ptr / 16), HEX_MI, result);
		printf_putnbr_based((ptr % 16), HEX_MI, result);
	}
	else
		printf_putnbr_based(ptr, HEX_MI, result);
}

void	printf_putnbr_based(long long nbr, char *base, int *count)
{
	long long	blen;

	if (*count == -1)
		return ;
	blen = get_base_len(base);
	if (nbr < 0)
	{
		printf_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr >= blen)
		printf_putnbr_based(nbr / blen, base, count);
	printf_putchar(base[nbr % blen], count);
}
