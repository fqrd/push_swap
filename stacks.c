/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:37:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:17:51 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_link	*lst_new(t_link **previous, int content)
{
	t_stack	*stack;
	t_link	*link;

	link = malloc(sizeof(t_link) * 1);
	if (!link)
		return (NULL);
	stack = malloc(sizeof(t_stack) * 1);
	if (!stack)
		return (NULL);
	stack->content = content;
	link->content = stack;
	link->next = NULL;
	link->previous = *previous;
	if (*previous)
		(*previous)->next = link;
	return (link);
}

/*t_stack	*lst_create(int argc, char *argv[])
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
}*/

int	lst_clear(t_link **lst, int val)
{
	t_link	*pre;

	if (lst)
	{
		*lst = lst_forward(*lst);
		while (*lst != NULL)
		{
			if (!(*lst)->previous)
				break ;
			pre = (*lst)->previous;
			free((*lst)->content);
			lst_delete(lst);
			*lst = pre;
		}
	}
	free(*lst);
	lst = NULL;
	return (val);
}

void	lst_delete(t_link **lst)
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
