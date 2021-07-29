/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:44:18 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/29 17:46:58 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switchy(t_list **x)
{
	t_list	*first;
	t_list	*next;

	first = ft_lstfirst(*x);
	next = first->next;
	if (ft_lstsize(first) < 2)
		return ;
	first->previous = next;
	first->next = next->next;
	next->next = first;
	next->previous = NULL;
	return ;
}

void	sa(t_list **a)
{
	switchy(a);

}

void	sb(t_list **b)
{
	switchy(b);
}

void	ss(t_list **a, t_list **b)
{
	switchy(a);
	switchy(b);
	return ;
}
