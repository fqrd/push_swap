/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:22:32 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 11:59:59 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	find_closest_r(t_stack **a, t_route **route, t_obj **obj)
{
	size_t	i;

	i = 0;
	*a = lst_rewind(*a);
	while (*a)
	{
		if ((*a)->index <= (*obj)->group_inc)
		{
			(*route)->candidate_top_position = (int) i; 
			(*route)->candidate_top_index = (*a)->index; 
			break;
		}
		if (!(*a)->next)
			break;
		*a = (*a)->next;
		i++;
	}
}

static void	find_closest_rr(t_stack **a, t_route **route, t_obj **obj)
{
	size_t	i;

	i = 1;
	*a = lst_forward(*a);
	while (*a)
	{
		if ((*a)->index <= (*obj)->group_inc)
		{
			(*route)->candidate_btm_position = (int) i; 
			(*route)->candidate_btm_index = (*a)->index; 
			break;
		}
		if (!(*a)->previous)
			break;
		*a = (*a)->previous;
		i++;
	}
}

void find_candidate(t_stack **a, t_route **route, t_obj **obj)
{
	find_closest_r(a, route, obj);
	find_closest_rr(a, route, obj);
}
