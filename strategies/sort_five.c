/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 16:36:45 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static void	isolate_start(t_list **a, t_list **b)
{
	if ((*a)->index == 1 || (*a)->index == 2)
		sort_five(pb(a, b, 0), b);
	else
	{
		if ((*a)->next && (((*a)->next->index == 1 || (*a)->next->index == 2)))
			sort_five(ra(a), b);
		else if ((*a)->next && (*a)->next->next && 
			(((*a)->next->next->index == 1 || (*a)->next->next->index == 2)))
			sort_five(ra(a), b);
		else
			sort_five(rra(a), b);
	}
}

int	sort_five(t_list **a, t_list **b)
{
	int a_size;
	int b_size;

	*a = lst_rewind(*a);
	*b = lst_rewind(*b);
	a_size = lst_size(*a);
	b_size = lst_size(*b);
	if (a_size == 5 && b_size == 0 && lst_issorted(*a))
		return (1);
	if ((a_size == 5 && b_size == 0) ||
		(a_size == 4 && b_size == 1 && !lst_issorted(*a)))
		isolate_start(a, b);
	else if (a_size == 4 && b_size == 1 && lst_issorted(*a))
		sort_five(sa(pa(a, b, 0)), b);
	else if (a_size == 3 && b_size == 2)
	{
		if (lst_issorted(*a) && !lst_issorted(*b))
			sort_five(pa(pa(a, b, 0), b, 0), b);
		else if (lst_issorted(*a) && lst_issorted(*b))
			sb(b);
		else
			sort_three(a);	
	} 
	sort_five(a, b);
	return (0);
}
