/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:08 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:11:40 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

size_t	lst_size(t_link *lst)
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

int	lst_issorted(t_link *lst, int descending)
{
	lst = lst_rewind(lst);
	if (descending)
	{
		while (lst)
		{
			if (lst->next && ((t_stack *)(lst->content))->index <= ((t_stack *)(lst->next->content))->index)
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
			if (lst->next && ((t_stack *)(lst->content))->index >= ((t_stack *)(lst->next->content))->index)
				return (0);
			if (!lst->next)
				break ;
			lst = lst->next;
		}
	}
	return (1);
}
