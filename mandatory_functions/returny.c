/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:26 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/24 11:51:31 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	returny(t_stack **x)
{
	t_stack	*top;
	t_stack	*bottom;

	bottom = lst_rewind(*x);
	if (!bottom || !bottom->next)
		return ;
	top = lst_forward(*x);
	bottom->next->previous = NULL;
	bottom->next = NULL;
	bottom->previous = top;
	top->next = bottom;
	return ;
}

t_stack	**ra(t_stack **a)
{
	returny(a);
	print_action("ra");
	return (a);
}

t_stack	**rb(t_stack **b)
{
	returny(b);
	print_action("rb");
	return (b);
}

t_stack	**rr(t_stack **a, t_stack **b, int pass_b)
{
	returny(a);
	returny(b);
	print_action("rr");
	if (pass_b)
		return (b);
	return (a);
}
