/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:37:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/30 16:17:45 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(t_list **previous, int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list) * 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->previous = *previous;
	if (*previous)
		(*previous)->next = list;
	return (list);
}

t_list	*create_list(int *p)
{
	int		i;
	t_list	*next;
	t_list	*previous;

	i = 0;
	next = NULL;
	previous = NULL;
	while (p[i] != INT_MIN)
	{
		next = ft_lstnew(&previous, p[i]);
		if (previous)
			previous->next = next;
		previous = next;
		i++;
	}
	previous->next = NULL;
	return (previous);
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
