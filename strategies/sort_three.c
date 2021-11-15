/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:38 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 15:34:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_three(t_list **a)
{
	// display_stacks(*a, *a);

	*a = lst_rewind(*a);

	if (lst_issorted(*a))
		return (1);
	if (((*a)->index == 2 && (*a)->next->index == 3) || 
		((*a)->index == 1 && (*a)->next->index == 3))
	{
		rra(a);
		printf("rra\n");
		sort_three(a);
	}
	else if ((*a)->index == 3 && (*a)->next->index == 1)
	{
		ra(a);
		printf("ra\n");
		sort_three(a);
	}
	else
	{
		sa(a);
		printf("sa\n");
		sort_three(a);
	}
	return (0);
}