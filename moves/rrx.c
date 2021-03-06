/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:46:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 22:15:28 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rrx(t_stack **x)
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
	rrx(a);
	ft_putstr("rra\n");
	return (a);
}

t_stack	**rrb(t_stack **b)
{
	rrx(b);
	ft_putstr("rrb\n");
	return (b);
}

t_stack	**rrr(t_stack **a, t_stack **b, int pass_b)
{
	rrx(a);
	rrx(b);
	ft_putstr("rrr\n");
	if (pass_b)
		return (b);
	return (a);
}
