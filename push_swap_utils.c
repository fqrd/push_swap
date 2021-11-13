/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:08 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 13:54:11 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	lst = ft_lsttop(lst);
	while (lst)
	{
		lst = lst->previous;
		i++;
	}
	return (i);
}

t_list	*ft_lstbottom(t_list *lst)
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

t_list	*ft_lsttop(t_list *lst)
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
