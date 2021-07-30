/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/30 15:43:25 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushy(t_list **x, t_list **y)
{
	t_list	*top_x;
	t_list	*top_y;

	top_y = NULL;
	if (ft_lstsize(ft_lstfirst(*x)))
	{
		top_x = ft_lstlast(*x);
		if (ft_lstsize(ft_lstfirst(*y)) > 0)
			top_y = ft_lstlast(*y);
		if (top_y)
			printf("content: %d\n", top_y->content);
		*y = ft_lstnew(&top_y, top_x->content);
		*x = ft_lstdelone(top_x);
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
