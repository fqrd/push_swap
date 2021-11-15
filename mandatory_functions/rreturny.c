/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rreturny.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:46:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 16:06:18 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rreturny(t_list **x)
{
	t_list	*top;
	t_list	*bottom;

	bottom = lst_rewind(*x);
	if (!bottom || !bottom->next)
		return ;
	top = lst_forward(*x);
	top->previous->next = NULL;
	top->previous = NULL;
	top->next = bottom;
	bottom->previous = top;
	return ;
}

t_list	**rra(t_list **a)
{
	rreturny(a);
	print_action("rra");
	return (a);
}

t_list	**rrb(t_list **b)
{
	rreturny(b);
	print_action("rrb");
	return (b);
}

t_list	**rrr(t_list **a, t_list **b, int pass_b)
{
	rreturny(a);
	rreturny(b);
	print_action("rrr");
	if (pass_b)
		return (b);
	return (a);
}
