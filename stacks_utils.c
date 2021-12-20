/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:08 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:27:35 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

size_t	lst_size(t_stack *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	lst = lst_rewind(lst);
	while (lst)
	{
		i++;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	lst = lst_rewind(lst);
	return (i);
}

int	lst_issorted(t_stack *lst, int descending)
{
	lst = lst_rewind(lst);
	if (descending)
	{
		while (lst)
		{
			if (lst->next && lst->index <= lst->next->index)
				return (0);
			if (!lst->next)
				break ;
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			if (lst->next && lst->index >= lst->next->index)
				return (0);
			if (!lst->next)
				break ;
			lst = lst->next;
		}
	}
	return (1);
}
