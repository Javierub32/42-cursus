/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:30:12 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:30:14 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + num * 10;
		i++;
	}
	return (num * neg);
}
