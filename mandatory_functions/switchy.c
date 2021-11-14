/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:44:18 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/14 18:26:58 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	switchy(t_list **x)
{
	t_list	*top;
	t_list	*next;

	top = lst_rewind(*x);
	if (!top || !top->next)
		return ;
	next = top->next;
	top->next = next->next;
	if (next->next)
		next->next->previous = top;
	top->previous = next;
	next->next = top;
	next->previous = NULL;
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
