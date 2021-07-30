/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:37:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/30 15:23:49 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(t_list *previous, int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list) * 1);
	if (!list || !content)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->previous = previous;
	return (list);
}

t_list	*ft_lstfirst(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (lst->previous == NULL)
				return (lst);
			lst = lst->previous;
		}
	}
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!(lst->next))
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	if (lst != NULL && *del != NULL)
	{
		while (*lst)
			del(*lst);
	}
	lst = NULL;
}

t_list	*ft_lstdelone(t_list *lst)
{
	t_list	*left;

	left = NULL;
	if (!lst)
		return (left);
	if (lst->next)
	{
		left = lst->next;
		lst->next->previous = lst->previous;
	}
	if (lst->previous)
	{
		left = lst->previous;
		lst->previous->next = lst->next;
	}
	lst->next = NULL;
	lst->previous = NULL;
	lst = NULL;
	free(lst);
	return (left);
}
