/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:52:01 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:34:42 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_route	*route_rewind(t_route *lst)
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

void	clear_routes(t_route **route)
{
	t_route	*p;

	*route = route_rewind(*route);
	while (*route)
	{
		if (!(*route)->next)
		{
			free(*route);
			break ;
		}
		p = (*route)->next;
		free (*route);
		*route = p;
	}
}

static t_route	*best_route(t_route **route)
{
	int		best;
	t_route	*p;

	*route = route_rewind(*route);
	best = (*route)->operations;
	p = *route;
	while (*route)
	{
		if ((*route)->operations < best)
		{
			best = (*route)->operations;
			p = *route;
		}
		if (!(*route)->next)
			break ;
		*route = (*route)->next;
	}
	return (p);
}

static void	apply_route(t_route *route, t_stack **a, t_stack **b)
{
	while (route->rr-- > 0)
		rr(a, b, 0);
	while (route->rrr-- > 0)
		rrr(a, b, 0);
	while (route->ra-- > 0)
		ra(a);
	while (route->rra-- > 0)
		rra(a);
	while (route->rb-- > 0)
		rb(b);
	while (route->rrb-- > 0)
		rrb(b);
}

int	find_and_apply_route(t_stack **a, t_stack **b, t_candidate **c)
{
	t_route	*route;

	route = NULL;
	*c = candidate_rewind(*c);
	while (*c)
	{
		route = map_routes(c, route, -1, -1);
		if (!route)
			return (0);
		if (!(*c)->next)
			break ;
		*c = (*c)->next;
	}
	clear_candidates(c, 1);
	apply_route(best_route(&route), a, b);
	clear_routes(&route);
	return (1);
}
