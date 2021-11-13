/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:44:18 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 13:53:35 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	switchy(t_list **x)
{
	t_list	*top;
	t_list	*pre;

	top = ft_lsttop(*x);
	if (!top || !top->previous)
		return ;
	pre = top->previous;
	top->previous = pre->previous;
	top->next = pre;
	if (pre->previous)
		pre->previous->next = top;
	pre->previous = top;
	pre->next = NULL;
	return ;
}

void	sa(t_list **a)
{
	switchy(a);
}

void	sb(t_list **b)
{
	switchy(b);
}

void	ss(t_list **a, t_list **b)
{
	switchy(a);
	switchy(b);
	return ;
}
