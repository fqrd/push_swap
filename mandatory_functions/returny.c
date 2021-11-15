/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:26 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 16:07:38 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	returny(t_list **x)
{
	t_list	*top;
	t_list	*bottom;

	bottom = lst_rewind(*x);
	if (!bottom || !bottom->next)
		return ;
	top = lst_forward(*x);
	bottom->next->previous = NULL;
	bottom->next = NULL;
	bottom->previous = top;
	top->next = bottom;
	return ;
}

t_list	**ra(t_list **a)
{
	returny(a);
	print_action("ra");
	return (a);
}

t_list	**rb(t_list **b)
{
	returny(b);
	print_action("rb");
	return (b);
}

t_list	**rr(t_list **a, t_list **b, int pass_b)
{
	returny(a);
	returny(b);
	print_action("rr");
	if (pass_b)
		return (b);
	return (a);
}
