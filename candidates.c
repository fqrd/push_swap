/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:22:32 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 14:20:55 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_candidate	*init_candidate(t_candidate *previous)
{
	t_candidate	*candidate;

	candidate = malloc(sizeof(t_candidate) * 1);
	if (!candidate)
	{
		clear_candidates(&previous, 0);
		return (NULL);
	}
	candidate->index = -1;
	candidate->position = -1;
	candidate->destination = -1;
	candidate->nra = 0;
	candidate->nrra = 0;
	candidate->nrb = 0;
	candidate->previous = previous;
	if (previous)
		(previous)->next = candidate;
	candidate->next = NULL;
	return (candidate);
}

static t_candidate	*find_closest_r(t_stack **a, t_context **context,
	t_candidate *c)
{
	size_t		i;

	i = 0;
	*a = lst_rewind(*a);
	while (*a)
	{
		c = init_candidate(c);
		if (!c)
			return (NULL);
		c->index = (*a)->index;
		c->position = (int) i;
		c->nra = c->position;
		c->nrra = (int)((*context)->sizea - i);
		if (!(*a)->next)
			break ;
		*a = (*a)->next;
		i++;
	}
	return (c);
}

t_candidate	*find_candidates(t_stack **a, t_context **context, t_candidate *c)
{
	c = find_closest_r(a, context, c);
	if (!c)
		return (NULL);
}
