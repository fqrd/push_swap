/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrbrrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/29 15:36:13 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *a)
{
	t_list	*last;
	t_list	*first;

	if (ft_lstsize(a) < 2)
		return ;
	last = ft_lstlast(a);
	first = ft_lstfirst(a);
	if (last->previous)
		last->previous->next = NULL;
	last->previous = NULL;
	last->next = first;
	first->previous = last;
	return ;
}

void	rrb(t_list *b)
{
	t_list	*last;
	t_list	*first;

	if (ft_lstsize(b) < 2)
		return ;
	last = ft_lstlast(b);
	first = ft_lstfirst(b);
	if (last->previous)
		last->previous->next = NULL;
	last->previous = NULL;
	last->next = first;
	first->previous = last;
	return ;
}

void	rrr(t_list *a, t_list *b)
{
	rra(a);
	rrb(b);
	return ;
}
