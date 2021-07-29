/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/29 17:45:07 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushy(t_list *x, t_list *y)
{
	t_list	*top_x;
	t_list	*top_y;

	top_y = NULL;
	if (!x)
		return ;
	if (ft_lstsize(ft_lstfirst(x)))
	{
		top_x = ft_lstlast(x);
		if (y && ft_lstsize(ft_lstfirst(y)))
			top_y = ft_lstlast(y);
		ft_lstnew(top_y, top_x->content);
		ft_lstdelone(x);
	}
	return ;
}

void pa(t_list *a, t_list *b)
{
	push(a, b);
}

void pb(t_list *a, t_list *b)
{
	push(b, a);
}