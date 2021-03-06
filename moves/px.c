/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 22:15:22 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	px(t_stack **x, t_stack **y)
{
	t_stack	*topx;
	t_stack	*topy;

	topx = lst_rewind(*x);
	topy = lst_rewind(*y);
	if (topx)
	{
		*x = topx->next;
		*y = topx;
		if (topx->next)
			topx->next->previous = NULL;
		topx->next = topy;
		if (topy)
			topy->previous = topx;
	}
}

t_stack	**pa(t_stack **a, t_stack **b, int pass_b)
{
	px(b, a);
	ft_putstr("pa\n");
	if (pass_b)
		return (b);
	return (a);
}

t_stack	**pb(t_stack **a, t_stack **b, int pass_b)
{
	px(a, b);
	ft_putstr("pb\n");
	if (pass_b)
		return (b);
	return (a);
}
