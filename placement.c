/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:53:48 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 12:23:39 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	get_index_position(t_stack **b, int index)
{
	int i;

	i = 0;
	printf("looking for: %d\n", index);
	*b = lst_rewind(*b);
	while (*b)
	{
		printf("b->index: %d\n", (*b)->index);
		if ((*b)->index == index)
		{
			printf("found: %d[%d]\n", index, i);
			return (i);
		}
		if (!(*b)->next)
		{
			printf("break");
			break;
		}
		*b = (*b)->next;
		i++;
	}
	return (-1);
}

static int get_opening(t_stack **b, int index)
{
	int i;
	int difference;
	int place;

	printf("looking for: %d\n", index);
	*b = lst_rewind(*b);
	i = 0;
	difference = -1;
	place = -1;
	while (*b)
	{
		printf("b->index: %d / >0 && < diff: %d / diff: %d\n", (*b)->index, index - (*b)->index, difference);
		if ((index - (*b)->index > 0 && index - (*b)->index < difference)
			|| ((difference == -1 && index - (*b)->index > 0)))
		{
			place = i;
			difference = index - (*b)->index;
		}
		if (!(*b)->next)
			break;
		*b = (*b)->next;
		i++;
	}
	return (place);
}

static int	find_opening(t_stack **b, int index, t_obj **obj)
{
	if ((*obj)->sizeb > 0)
	{
		// if (index > (*obj)->highestb)
		// {
		// 	// if index is highest. lowest first.
		// 	printf("[Lowest first][%d]\n", (*obj)->lowestb);
		// 	return (get_index_position(b, (*obj)->lowestb));
		// }
		if (index > (*obj)->highestb || index < (*obj)->lowestb)
		{
			// if index is lowest. highest first.
			printf("[Highest first][%d]\n", (*obj)->highestb);
			return (get_index_position(b, (*obj)->highestb));
		}
		else
		{
			// if higher on stack. closest higher first, closest lower last 
			printf("[Get opening moves]\n");
			return (get_opening(b, index));
		}
	}
}

void find_destination(t_stack **b, t_route **route, t_obj **obj)
{
	(*route)->candidate_top_destination = find_opening(b, (*route)->candidate_top_index, obj);
	(*route)->candidate_btm_destination = find_opening(b, (*route)->candidate_btm_index, obj);
	printf("DEBUG: sizeb: %ld / top dest: %d / btm dest: %d\n", 
		(*obj)->sizeb, (*route)->candidate_top_destination, (*route)->candidate_btm_destination);
}
