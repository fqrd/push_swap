/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rreturny.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:46:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/30 11:25:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rreturny(t_list **x)
{
	t_list	*last;
	t_list	*first;

	first = ft_lstfirst(*x);
	if (ft_lstsize(first) < 2)
		return ;
	last = ft_lstlast(*x);
	if (last->previous)
		last->previous->next = NULL;
	last->previous = NULL;
	last->next = first;
	first->previous = last;
	return ;
}

void	rra(t_list **a)
{
	rreturny(a);
}

void	rrb(t_list **b)
{
	rreturny(b);
}

void	rrr(t_list **a, t_list **b)
{
	rreturny(a);
	rreturny(b);
	return ;
}
