/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:54:30 by jurbanej          #+#    #+#             */
/*   Updated: 2025/06/18 11:54:32 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] && count != -1)
	{
		if (str[i] != '%')
			printf_putchar(str[i], &count);
		else if (str[i + 1])
			printf_select_format(args, str[++i], &count);
		else
			count = -1;
		i++;
	}
	va_end(args);
	return (count);
}

void	printf_select_format(va_list args, char format, int *count)
{
	if (format == 'c')
		printf_putchar(va_arg(args, int), count);
	else if (format == 's')
		printf_putstr(va_arg(args, char *), count);
	else if (format == 'p')
		printf_putpointer(va_arg(args, unsigned long long), count);
	else if (format == 'd')
		printf_putnbr_based(va_arg(args, int), DEC, count);
	else if (format == 'i')
		printf_putnbr_based(va_arg(args, int), DEC, count);
	else if (format == 'u')
		printf_putnbr_based(va_arg(args, unsigned int), DEC, count);
	else if (format == 'x')
		printf_putnbr_based(va_arg(args, unsigned int), HEX_MI, count);
	else if (format == 'X')
		printf_putnbr_based(va_arg(args, unsigned int), HEX_MA, count);
	else if (format == '%')
		printf_putchar('%', count);
	else
		*count = -1;
}
