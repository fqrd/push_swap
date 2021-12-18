/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:22:32 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/19 00:11:05 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_candidate	*init_candidate(void)
{
	t_candidate	*candidate;

	candidate = malloc(sizeof(t_candidate) * 1);
	if (!candidate)
		return (NULL);
	return (candidate);
}

void	candidate_reset(t_candidate **candidate)
{
	(*candidate)->index = -1;
	(*candidate)->position = -1;
	(*candidate)->destination = -1;
	(*candidate)->nra = 0;
	(*candidate)->nrra = 0;
	(*candidate)->nrb = 0;
}

static void	find_closest_r(t_stack **a, t_context **context,
	t_candidate **candidate)
{
	size_t	i;

	i = 0;
	*a = lst_rewind(*a);
	while (*a)
	{
		if ((*a)->index <= (*context)->group_inc)
		{
			(*candidate)->index = (*a)->index;
			(*candidate)->position = (int) i;
			(*candidate)->nra = (*candidate)->position;
			(*candidate)->nrra = (int)((*context)->sizea - i);
			break ;
		}
		if (!(*a)->next)
			break ;
		*a = (*a)->next;
		i++;
	}
}

static void	find_closest_rr(t_stack **a, t_context **context,
	t_candidate **candidate)
{
	size_t	i;

	i = 0;
	*a = lst_forward(*a);
	while (*a)
	{
		if ((*a)->index <= (*context)->group_inc)
		{
			(*candidate)->index = (*a)->index;
			(*candidate)->position = (int)((*context)->sizea - i) - 1;
			(*candidate)->nra = (*candidate)->position;
			(*candidate)->nrra = (int)(i + 1);
			break ;
		}
		if (!(*a)->previous)
			break ;
		*a = (*a)->previous;
		i++;
	}
}

void	find_candidate(t_stack **a, t_context **context,
	t_candidate **top, t_candidate **btm)
{
	find_closest_r(a, context, top);
	find_closest_rr(a, context, btm);
}
