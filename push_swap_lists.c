/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:37:24 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 18:23:20 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

t_list	*create_list(int argc, char *argv[])
{
	size_t		i;
	t_list		*next;
	t_list		*previous;

	i = argc;
	next = NULL;
	previous = NULL;
	while (i-- > 1)
	{
		printf("ft_atoi: %d \n", ft_atoi(argv[i]));
		next = ft_lstnew(&previous, ft_atoi(argv[i]));
		if (previous)
			previous->next = next;
		previous = next;
	}
	previous->next = NULL;
	return (previous);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*pre;

	if (lst != NULL)
	{
		*lst = ft_lsttop(*lst);
		while (*lst)
		{
			pre = (*lst)->previous;
			ft_lstdelone(&*lst);
			*lst = pre;
		}
	}
	lst = NULL;
}

void	ft_lstdelone(t_list **lst)
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

t_list	*lst_rewind(t_list *lst)
{
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}
