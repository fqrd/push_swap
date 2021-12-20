/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:26 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 12:52:55 by fcaquard         ###   ########.fr       */
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
	ft_putstr("ra\n");
	return (a);
}

t_stack	**rb(t_stack **b)
{
	returny(b);
	ft_putstr("rb\n");
	return (b);
}

t_stack	**rr(t_stack **a, t_stack **b, int pass_b)
{
	returny(a);
	returny(b);
	ft_putstr("rr\n");
	if (pass_b)
		return (b);
	return (a);
}
