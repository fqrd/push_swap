/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:26 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:51:30 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rx(t_stack **x)
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
	rx(a);
	ft_putstr("ra\n");
	return (a);
}

t_stack	**rb(t_stack **b)
{
	rx(b);
	ft_putstr("rb\n");
	return (b);
}

t_stack	**rr(t_stack **a, t_stack **b, int pass_b)
{
	rx(a);
	rx(b);
	ft_putstr("rr\n");
	if (pass_b)
		return (b);
	return (a);
}
