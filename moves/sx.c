/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:44:18 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 22:15:40 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sx(t_stack **x)
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
	sx(a);
	ft_putstr("sa\n");
	return (a);
}

t_stack	**sb(t_stack **b)
{
	sx(b);
	ft_putstr("sb\n");
	return (b);
}

t_stack	**ss(t_stack **a, t_stack **b, int pass_b)
{
	sx(a);
	sx(b);
	ft_putstr("ss\n");
	if (pass_b)
		return (b);
	return (a);
}
