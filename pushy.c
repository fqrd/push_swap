/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/31 15:22:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushy(t_list **x, t_list **y)
{
	t_list	*top_x;
	t_list	*top_y;

	top_y = NULL;
	if (*x)
	{
		top_x = ft_lsttop(*x);
		if (*y)
			top_y = ft_lsttop(*y);
		*y = ft_lstnew(&top_y, top_x->content);
		*x = top_x->previous;
		ft_lstdelone(&top_x);
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
