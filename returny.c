/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:26 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/30 18:54:54 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	returny(t_list **x)
{
	t_list	*last;
	t_list	*first;

	if (!*x)
		return ;
	first = ft_lstbottom(*x);
	if (ft_lstsize(first) < 2)
		return ;
	last = ft_lsttop(*x);
	if (first->next)
		first->next->previous = NULL;
	first->next = NULL;
	first->previous = last;
	last->next = first;
	return ;
}

void	ra(t_list **a)
{
	returny(a);
	return ;
}

void	rb(t_list **b)
{
	returny(b);
	return ;
}

void	rr(t_list **a, t_list **b)
{
	returny(a);
	returny(b);
	return ;
}
