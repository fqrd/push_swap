/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:53:48 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/19 00:15:39 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	get_position(t_stack **b, int index)
{
	int	i;

	i = 0;
	*b = lst_rewind(*b);
	while (*b)
	{
		if ((*b)->index == index)
			return (i);
		if (!(*b)->next)
			break ;
		*b = (*b)->next;
		i++;
	}
	return (-1);
}

static int	get_opening(t_stack **b, int index)
{
	int	i;
	int	difference;
	int	place;

	*b = lst_rewind(*b);
	i = 0;
	difference = -1;
	place = -1;
	while (*b)
	{
		if ((index - (*b)->index > 0 && index - (*b)->index < difference)
			|| ((difference == -1 && index - (*b)->index > 0)))
		{
			place = i;
			difference = index - (*b)->index;
		}
		if (!(*b)->next)
			break ;
		*b = (*b)->next;
		i++;
	}
	return (place);
}

static void	find_opening(t_stack **b, t_candidate **candidate,
	t_context **context)
{
	int	result;

	if ((*context)->sizeb > 0)
	{
		if ((*candidate)->index > (*context)->highestb
			|| (*candidate)->index < (*context)->lowestb)
			(*candidate)->destination = get_position(b, (*context)->highestb);
		else
			(*candidate)->destination = get_opening(b, (*candidate)->index);
	}
	(*candidate)->nrb = (*candidate)->destination;
	(*candidate)->nrrb = (*context)->sizeb - (*candidate)->destination;
}

void	find_destination(t_stack **b, t_candidate **top, t_candidate **btm,
	t_context **context)
{
	find_opening(b, top, context);
	find_opening(b, btm, context);
}
