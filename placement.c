/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:53:48 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/17 18:14:49 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void get_opening_moves(t_stack **b, int index, t_route **route)
{
	size_t i;
	int difference;
	int place;

	*b = lst_rewind(*b);
	i = 0;
	difference = (*b)->index - index;
	while (*b)
	{
		if ((*b)->index - index > 0 && (*b)->index - index < difference)
		{
			(*route)->moves_b = i;
			difference = (*b)->index - index;
		}
		if (!(*b)->next)
			break;
		*b = (*b)->next;
		i++;
	}
}

static void	find_opening(t_stack **b, int index, t_route **route, t_obj **obj)
{

	if ((*obj)->sizeb > 0)
	{
		if (index > (*obj)->highestb)
		{
			// if index is highest. lowest first.
			printf("[Lowest first]\n");
			get_opening_moves(b, (*obj)->lowestb, route);
		}
		else if (index < (*obj)->lowestb)
		{
			// if index is lowest. highest first.
			printf("[Highest first]\n");
			get_opening_moves(b, (*obj)->highestb, route);
		}
		else
		{
			// if higher on stack. closest higher first, closest lower last 
			printf("[get opening moves]\n");
			get_opening_moves(b, index, route);
		}
	}
}

void find_best_opening(t_stack **b, t_route **route, t_obj **obj)
{
	find_opening(b, (*route)->ra_index, route, obj);
	find_opening(b, (*route)->rra_index, route, obj);
	printf("Leaving best_opening\n");
}
