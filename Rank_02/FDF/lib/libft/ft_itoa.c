/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:30:40 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:30:41 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_length(long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	if (num >= 0 && num <= 9)
		len++;
	return (len);
}

static void	check_base_cases(char *str, long *num)
{
	if (*num < 0)
	{
		str[0] = '-';
		*num = -(*num);
	}
	if (*num == 0)
		str[0] = '0';
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	long	num;
	char	*str;

	num = n;
	len = number_length(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = len - 1;
	check_base_cases(str, &num);
	while (num != 0)
	{
		str[i] = ((num % 10) + '0');
		num = num / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}
