/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:37:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/20 19:25:25 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*lst_new(t_list **previous, int content)
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

t_list	*lst_create(int argc, char *argv[])
{
	int		i;
	t_list		*current;
	t_list		*previous;

	i = 0;
	current = NULL;
	previous = NULL;
	while (++i < argc)
	{
		current = lst_new(&previous, ft_atoi(argv[i]));
		if (previous)
			previous->next = current;
		previous = current;
	}
	previous->next = NULL;
	return (lst_rewind(previous));
}

int	lst_clear(t_list **lst, int val)
{
	t_list	*pre;

	if (lst != NULL)
	{
		*lst = lst_forward(*lst);
		while (*lst)
		{
			pre = (*lst)->previous;
			lst_delete(&*lst);
			*lst = pre;
		}
	}
	lst = NULL;
	return (val);
}

void	lst_delete(t_list **lst)
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
