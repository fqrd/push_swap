/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rreturny.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:46:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/31 23:22:55 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rreturny(t_list **x)
{
	t_list	*top;
	t_list	*bottom;

	bottom = ft_lstbottom(*x);
	if (!bottom || !bottom->next)
		return ;
	top = ft_lsttop(*x);
	top->previous->next = NULL;
	top->previous = NULL;
	top->next = bottom;
	bottom->previous = top;
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
