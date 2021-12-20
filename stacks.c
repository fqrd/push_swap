/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:37:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 23:48:02 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*lst_new(t_stack **previous, int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack) * 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->previous = *previous;
	if (*previous)
		(*previous)->next = list;
	return (list);
}

t_stack	*lst_create(int argc, char *argv[])
{
	int		i;
	t_stack	*current;
	t_stack	*previous;

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
