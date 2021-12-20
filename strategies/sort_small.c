/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:38 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 15:50:29 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_small(t_stack **a)
{
	*a = lst_rewind(*a);
	if (lst_issorted(*a, 0))
		return (1);
	if (((*a)->index == 2 && (*a)->next->index == 3)
		|| ((*a)->index == 1 && (*a)->next->index == 3))
		sort_small(rra(a));
	else if ((*a)->index == 3 && (*a)->next->index == 1)
		sort_small(ra(a));
	else
		sort_small(sa(a));
	return (0);
}
