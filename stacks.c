/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:37:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/22 20:56:56 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*lst_new(t_stack **previous, int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack) * 1);
	if (!list)
	{
		lst_clear(previous, 0);
		return (NULL);
	}
	list->content = content;
	list->next = NULL;
	list->previous = *previous;
	if (*previous)
		(*previous)->next = list;
	return (list);
}

int	lst_clear(t_stack **lst, int val)
{
	t_stack	*pre;

	if (lst)
	{
		*lst = lst_forward(*lst);
		while (*lst != NULL)
		{
			if (!(*lst)->previous)
				break ;
			pre = (*lst)->previous;
			lst_delete(lst);
			*lst = pre;
		}
	}
	free(*lst);
	lst = NULL;
	return (val);
}

void	lst_delete(t_stack **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			(*lst)->next->previous = (*lst)->previous;
		if ((*lst)->previous)
			(*lst)->previous->next = (*lst)->next;
		(*lst)->next = NULL;
		(*lst)->previous = NULL;
		free(*lst);
		*lst = NULL;
	}
}
