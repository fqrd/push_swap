/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:22:32 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/19 19:46:07 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_candidate	*init_candidate(t_candidate *previous)
{
	t_candidate	*candidate;
	
	candidate = malloc(sizeof(t_candidate) * 1);
	if (!candidate)
		return (NULL);
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

t_candidate *candidate_rewind(t_candidate *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->previous)
				return (lst);
			lst = lst->previous;
		}
	}
	return (lst);
}

static t_candidate	*find_closest_r(t_stack **a, t_context **context,
	t_candidate *c)
{
	size_t	i;
	int		found;

	found = 0;
	i = 0;
	*a = lst_rewind(*a);
	while (*a)
	{
		if ((*a)->index <= (*context)->group_inc)
		{
			c = init_candidate(c);
			if (!c)
				return (0);
			
			c->index = (*a)->index;
			c->position = (int) i;
			c->nra = c->position;
			c->nrra = (int)((*context)->sizea - i);
			found++;
		}
		if (!(*a)->next || found == (*context)->group_size)
			break ;
		*a = (*a)->next;
		i++;
	}
	return (c);
}

static t_candidate	*find_closest_rr(t_stack **a, t_context **context,
	t_candidate *c)
{
	size_t	i;
	int		found;

	found = 0;
	i = 0;
	*a = lst_forward(*a);
	while (*a)
	{
		if ((*a)->index <= (*context)->group_inc)
		{
			c = init_candidate(c);
			if (!c)
				return (0);
			
			c->index = (*a)->index;
			c->position = (int)((*context)->sizea - i) - 1;
			c->nra = c->position;
			c->nrra = (int)(i + 1);
			found++;
		}
		if (!(*a)->previous || found == (*context)->group_size)
			break ;
		*a = (*a)->previous;
		i++;
	}
	return (c);
}

t_candidate	*find_candidates(t_stack **a, t_context **context, t_candidate *c)
{
	c = find_closest_r(a, context, c);
	c = find_closest_rr(a, context, c);
}
