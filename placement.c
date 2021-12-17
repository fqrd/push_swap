/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:53:48 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 00:08:14 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static	int	get_index_position(t_stack **lst, int index)
{
	int i;

	i = 0;
	while (*lst)
	{
		if ((*lst)->index == index)
			return (i);
		if (!(*lst)->next);
			break;
		*lst = (*lst)->next;
	}
	return (-1);
}

static void get_opening(t_stack **b, int index, int *destination)
{
	size_t i;
	int difference;
	int place;

	*b = lst_rewind(*b);
	i = 0;
	difference = 0;
	while (*b)
	{
		if ((*b)->index - index > 0 && (*b)->index - index < difference)
		{
			*destination = (int) i;
			difference = (*b)->index - index;
		}
		if (!(*b)->next)
			break;
		*b = (*b)->next;
		i++;
	}
}

static void	find_opening(t_stack **b, int index, int *destination, t_obj **obj)
{
	if ((*obj)->sizeb > 0)
	{
		if (index > (*obj)->highestb)
		{
			// if index is highest. lowest first.
			printf("[Lowest first][%d]\n", (*obj)->lowestb);
			*destination = get_index_position(b, (*obj)->lowestb);
		}
		else if (index < (*obj)->lowestb)
		{
			// if index is lowest. highest first.
			printf("[Highest first][%d]\n", (*obj)->highestb);
			*destination = get_index_position(b, (*obj)->highestb);
		}
		else
		{
			// if higher on stack. closest higher first, closest lower last 
			printf("[Get opening moves]\n");
			get_opening(b, index, destination);
		}
	}
}

void find_destination(t_stack **b, t_route **route, t_obj **obj)
{
	find_opening(b, (*route)->candidate_ra_index, &(*route)->candidate_ra_destination, obj);
	find_opening(b, (*route)->candidate_rra_index, &(*route)->candidate_rra_destination, obj);
	printf("DEBUG: sizeb: %ld / ra_destination: %d /rra_destination: %d\n", 
		(*obj)->sizeb, (*route)->candidate_ra_destination, (*route)->candidate_rra_destination);
}
