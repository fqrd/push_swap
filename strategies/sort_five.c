/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/16 13:00:57 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	top_to_b(t_list **a, t_list **b)
{
	*a = lst_rewind(*a);
	if (lst_size(*a) <= 3)
		return (1);
	if ((*a)->index == 1 || (*a)->index == 2)
		return (top_to_b(pb(a, b, 0), b));
	if ((*a)->next && (((*a)->next->index == 1 || (*a)->next->index == 2)))
		return (top_to_b(ra(a), b));
	else if ((*a)->next && (*a)->next->next && 
		(((*a)->next->next->index == 1 || (*a)->next->next->index == 2)))
		return (top_to_b(ra(a), b));
	else
		return (top_to_b(rra(a), b));
	return (0);
}

static int	sort_a(t_list **x)
{
	*x = lst_rewind(*x);
	if (lst_issorted(*x))
		return (1);
	if (((*x)->index == 4 && (*x)->next->index == 5) || 
		((*x)->index == 3 && (*x)->next->index == 5))
		sort_a(rra(x));
	else if ((*x)->index == 5 && (*x)->next->index == 3)
		sort_a(ra(x));
	else
		sort_a(sa(x));
	return (0);
}

int	sort_five(t_list **a, t_list **b)
{
	int a_size;
	int b_size;
	int sorted_a;
	int sorted_b;

	*a = lst_rewind(*a);
	*b = lst_rewind(*b);
	a_size = lst_size(*a);
	b_size = lst_size(*b);
	sorted_a = lst_issorted(*a);
	sorted_b = lst_issorted(*b);
	if (a_size == 5 && sorted_a)
		return (1);
	if (a_size > 3)
		top_to_b(a, b);
	if (lst_size(*a) == 3 && !sorted_a)
		sort_a(a);
	if (!lst_issorted(*(pa(pa(a, b, 0), b, 0))))
		sa(a);
	sort_five(a, b);
	return (0);
}
