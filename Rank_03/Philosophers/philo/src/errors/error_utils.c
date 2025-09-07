/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// Hacer release al final

void	print_error(int error)
{
	if (error == ERR_MALLOC)
		printf("Error: Memory allocation failed\n");
	else if (error == ERR_THREAD)
		printf("Error: Thread creation failed\n");
	else if (error == ERR_MUTEX)
		printf("Error: Mutex initialization failed\n");
	else if (error == ERR_INVALID_ARG)
		printf("Error: Invalid argument\n");
	else if (error == ERR_ATOL)
		printf("Error: Invalid number\n");
	exit(1);
}
