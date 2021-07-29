/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papbrarbrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:02 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/29 15:34:22 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *a, t_list *b)
{
	t_list	*top_a;
	t_list	*top_b;

	top_b = NULL;
	if (ft_lstsize(a))
	{
		top_a = ft_lstlast(a);
		if (ft_lstsize(b))
			top_b = ft_lstlast(b);
		ft_lstnew(top_b, top_a->content);
		ft_lstdelone(a);
	}
	return ;
}

void	pb(t_list *a, t_list *b)
{
	t_list	*top_a;
	t_list	*top_b;

	top_a = NULL;
	if (ft_lstsize(b))
	{
		top_b = ft_lstlast(b);
		if (ft_lstsize(a))
			top_a = ft_lstlast(a);
		ft_lstnew(top_a, top_b->content);
		ft_lstdelone(b);
	}
	return ;
}

void	ra(t_list *a)
{
	t_list	*last;
	t_list	*first;

	if (ft_lstsize(a) < 2)
		return ;
	last = ft_lstlast(a);
	first = ft_lstfirst(a);
	if (first->next)
		first->next->previous = NULL;
	first->next = NULL;
	first->previous = last;
	last->next = first;
	return ;
}

void	rb(t_list *b)
{
	t_list	*last;
	t_list	*first;

	if (ft_lstsize(b) < 2)
		return ;
	last = ft_lstlast(b);
	first = ft_lstfirst(b);
	if (first->next)
		first->next->previous = NULL;
	first->next = NULL;
	first->previous = last;
	last->next = first;
	return ;
}

void	rr(t_list *a, t_list *b)
{
	ra(a);
	rb(b);
	return ;
}
