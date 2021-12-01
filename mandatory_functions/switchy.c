/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:44:18 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/01 16:43:47 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	switchy(t_stack **x)
{
	t_stack	*top;
	t_stack	*next;

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

t_stack	**sa(t_stack **a)
{
	switchy(a);
	print_action("sa", 1);
	return (a);
}

t_stack	**sb(t_stack **b)
{
	switchy(b);
	print_action("sb", 0);
	return (b);
}

t_stack	**ss(t_stack **a, t_stack **b, int pass_b)
{
	switchy(a);
	switchy(b);
	print_action("ss", 0);
	if (pass_b)
		return (b);
	return (a);
}
