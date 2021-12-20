/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:44:31 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	push_b(t_stack **a, t_stack **b)
{
	*a = lst_rewind(*a);
	if (lst_size(*a) <= 3)
		return (1);
	if ((*a)->index == 1 || (*a)->index == 2)
		return (push_b(pb(a, b, 0), b));
	if (((*a)->next && (((*a)->next->index == 1 || (*a)->next->index == 2)))
		|| ((*a)->next && (*a)->next->next
			&& (((*a)->next->next->index == 1
					|| (*a)->next->next->index == 2))))
		return (push_b(ra(a), b));
	else
		return (push_b(rra(a), b));
	return (0);
}

static int	sort(t_stack **x)
{
	*x = lst_rewind(*x);
	if (lst_issorted(*x, 0))
		return (1);
	if (((*x)->index == 4 && (*x)->next->index == 5)
		|| ((*x)->index == 3 && (*x)->next->index == 5))
		sort(rra(x));
	else if ((*x)->index == 5 && (*x)->next->index == 3)
		sort(ra(x));
	else
		sort(sa(x));
	return (0);
}

int	sort_medium(t_stack **a, t_stack **b)
{
	int	a_size;
	int	sorted_a;

	*a = lst_rewind(*a);
	*b = lst_rewind(*b);
	a_size = lst_size(*a);
	sorted_a = lst_issorted(*a, 0);
	if (a_size == 5 && sorted_a)
		return (1);
	if (a_size > 3)
		push_b(a, b);
	if (lst_size(*a) == 3 && !sorted_a)
		sort(a);
	if (!lst_issorted(*(pa(pa(a, b, 0), b, 0)), 0))
		sa(a);
	sort_medium(a, b);
	return (0);
}
