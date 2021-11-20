/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:08 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/20 19:25:44 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

size_t	lst_size(t_list *lst)
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
			break;
		lst = lst->next;
	}
	lst = lst_rewind(lst);
	return (i);
}

t_list	*lst_rewind(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->previous)
				return (lst);
			lst = lst->previous;
		}
	}
	return (lst);
}

t_list	*lst_forward(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->next)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

int	lst_issorted(t_list *lst)
{
	lst = lst_rewind(lst);
	while (lst)
	{
		if (lst->next && lst->index != lst->next->index - 1)
			return (0);
		if (!lst->next)
			break;
		lst = lst->next;
	}
	// printf("sorted:\n");
	// display_stacks(lst, lst);
	return (1);
}
