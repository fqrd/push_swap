/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rreturny.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:46:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/01 16:43:39 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rreturny(t_stack **x)
{
	t_stack	*top;
	t_stack	*bottom;

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

t_stack	**rra(t_stack **a)
{
	rreturny(a);
	print_action("rra", 1);
	return (a);
}

t_stack	**rrb(t_stack **b)
{
	rreturny(b);
	print_action("rrb", 0);
	return (b);
}

t_stack	**rrr(t_stack **a, t_stack **b, int pass_b)
{
	rreturny(a);
	rreturny(b);
	print_action("rrr", 0);
	if (pass_b)
		return (b);
	return (a);
}
