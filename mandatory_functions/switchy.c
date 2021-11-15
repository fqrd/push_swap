/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:44:18 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 16:07:52 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	switchy(t_list **x)
{
	t_list	*top;
	t_list	*next;

	top = lst_rewind(*x);
	if (!top || !top->next)
		return ;
	next = top->next;
	top->next = next->next;
	if (next->next)
		next->next->previous = top;
	top->previous = next;
	next->next = top;
	next->previous = NULL;
	return ;
}

t_list	**sa(t_list **a)
{
	switchy(a);
	print_action("sa");
	return (a);
}

t_list	**sb(t_list **b)
{
	switchy(b);
	print_action("sb");
	return (b);
}

t_list	**ss(t_list **a, t_list **b, int pass_b)
{
	switchy(a);
	switchy(b);
	print_action("ss");
	if (pass_b)
		return (b);
	return (a);
}
