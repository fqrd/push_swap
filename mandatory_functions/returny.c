/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:26 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 13:52:48 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	returny(t_list **x)
{
	t_list	*top;
	t_list	*bottom;

	bottom = ft_lstbottom(*x);
	if (!bottom || !bottom->next)
		return ;
	top = ft_lsttop(*x);
	bottom->next->previous = NULL;
	bottom->next = NULL;
	bottom->previous = top;
	top->next = bottom;
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
