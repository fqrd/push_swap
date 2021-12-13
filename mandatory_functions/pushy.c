/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/13 17:00:19 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushy(t_stack **x, t_stack **y)
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
	pushy(b, a);
	print_action("pa");
	if (pass_b)
		return (b);
	return (a);
}

t_stack	**pb(t_stack **a, t_stack **b, int pass_b)
{
	pushy(a, b);
	print_action("pb");
	if (pass_b)
		return (b);
	return (a);
}
