/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:31:15 by jurbanej          #+#    #+#             */
/*   Updated: 2025/04/29 10:31:17 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*actual;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	actual = *lst;
	while (actual != NULL)
	{
		next = actual->next;
		ft_lstdelone(actual, del);
		actual = next;
	}
	*lst = NULL;
}
