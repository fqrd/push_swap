/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 13:58:02 by fcaquard         ###   ########.fr       */
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
}

void	pa(t_list **a, t_list **b)
{
	pushy(b, a);
}

void	pb(t_list **a, t_list **b)
{
	pushy(a, b);
}
