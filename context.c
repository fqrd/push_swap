/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:55:23 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 15:59:51 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_context	*init_context(void)
{
	t_context *context;

	context = malloc(sizeof(t_context) * 1);
	if (!context)
		return (NULL);
	context->limita = 0;
	context->limitb = 0;
	context->sizea = 0;
	context->sizeb = 0;
	context->positiona = 0;
	context->positionb = 0;
	context->actions = 0;
	context->firsta = NULL;
	context->lasta = NULL;
	context->firstb = NULL;
	context->lastb = NULL;
	context->group_size = 0;
	context->group_inc = 0;
	context->pushed_inc = 0;
	context->highestb = 0; 
	context->lowestb = 0;

	return (context);
}

static void high_low(t_stack **b, t_context **context)
{
	size_t i;

	i = 0;
	*b = lst_rewind(*b);
	while (*b)
	{
		if (i == 0)
		{
			(*context)->highestb = (*b)->index;
			(*context)->lowestb = (*b)->index;
		}
		else
		{
			if ((*b)->index > (*context)->highestb)
				(*context)->highestb = (*b)->index;
			if ((*b)->index < (*context)->lowestb)
				(*context)->lowestb = (*b)->index;
		}
		if(!(*b)->next)
			break;
		*b = (*b)->next;
		i++;
	}
}

void	context_reset(t_stack **a, t_stack **b, t_context **context)
{
	(*context)->sizea = lst_size(*a);
	(*context)->sizeb = lst_size(*b);
	(*context)->limita = ((*context)->sizea / 2) + 1;
	(*context)->limitb = ((*context)->sizeb / 2) + 1;
	(*context)->firsta = lst_rewind(*a);
	(*context)->lasta = lst_forward(*a);
	(*context)->firstb = lst_rewind(*b);
	(*context)->lastb = lst_forward(*b);
	high_low(b, context);
	(*context)->group_size = 10;
	(*context)->pushed_inc = 0;
	(*context)->group_inc = (((*context)->pushed_inc / (*context)->group_size) + 1) * (*context)->group_size;

	// if ((*context)->sizea > 0)
	// 	printf("sizea: %zu / limita: %zu / firsta: %d / lasta: %d\n", 
	// 		(*context)->sizea, (*context)->limita, (*context)->firsta->index, (*context)->lasta->index);
	// if ((*context)->sizeb > 0)
	// 	printf("sizeb: %zu / limitb: %zu / firstb: %d / lastb: %d / highest: %d/ lowest: %d\n", 
	// 		(*context)->sizeb, (*context)->limitb, (*context)->firstb->index, (*context)->lastb->index, (*context)->highestb, (*context)->lowestb);
}