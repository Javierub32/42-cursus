/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:54:37 by jurbanej          #+#    #+#             */
/*   Updated: 2025/06/18 11:54:38 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define HEX_MI "0123456789abcdef"
# define HEX_MA "0123456789ABCDEF"
# define DEC "0123456789"

int		ft_printf(const char *str, ...);
void	printf_select_format(va_list args, char c, int *count);
void	printf_putchar(char c, int *count);
void	printf_putstr(char *str, int *count);
void	printf_putpointer(unsigned long long ptr, int *count);
void	printf_putnbr_based(long long nbr, char *base, int *count);
#endif
