/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/31 23:08:08 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushy(t_list **x, t_list **y)
{
	t_list	*topx;
	t_list	*topy;

	topx = ft_lsttop(*x);
	topy = ft_lsttop(*y);
	if (topx)
	{
		*y = ft_lstnew(&topy, topx->content);
		*x = topx->previous;
		ft_lstdelone(&topx);
	}
}

void	pa(t_list **a, t_list **b)
{
	pushy(a, b);
}

void	pb(t_list **a, t_list **b)
{
	pushy(b, a);
}
