/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/16 11:45:12 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushy(t_list **x, t_list **y)
{
	t_list	*topx;
	t_list	*topy;

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
	// set_indexes(x, lst_size(*x));
	// set_indexes(y, lst_size(*y));
}

t_list	**pa(t_list **a, t_list **b, int pass_b)
{
	pushy(b, a);
	print_action("pa");
	if (pass_b)
		return (b);
	return (a);
}

t_list	**pb(t_list **a, t_list **b, int pass_b)
{
	pushy(a, b);
	print_action("pb");
	if (pass_b)
		return (b);
	return (a);
}
