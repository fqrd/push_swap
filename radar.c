/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:52:01 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/19 19:48:06 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_route	*init_route(t_route *previous)
{
	t_route	*route;

	route = malloc(sizeof(t_route) * 1);
	if (!route)
		return (NULL);
	route->operations = 0;
	route->ra = -1;
	route->rra = -1;
	route->rb = -1;
	route->rrb = -1;
	route->rr = -1;
	route->rrr = -1;
	route->previous = previous;
	if (previous)
		previous->next = route;
	route->next = NULL;
	return (route);
}

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

static void	count_moves(t_route **route)
{
	if ((*route)->ra > -1)
		(*route)->operations += (*route)->ra;
	if ((*route)->rra > -1)
		(*route)->operations += (*route)->rra;
	if ((*route)->rb > -1)
		(*route)->operations += (*route)->rb;
	if ((*route)->rrb > -1)
		(*route)->operations += (*route)->rrb;
	if ((*route)->rr > -1)
		(*route)->operations += (*route)->rr;
	if ((*route)->rrr > -1)
		(*route)->operations += (*route)->rrr;
}

static void	double_moves(t_candidate **candidate, t_route **route)
{
	if ((*route)->ra > -1 && (*route)->rb > -1 && (*route)->ra <= (*route)->rb)
	{
		(*route)->rr = (*route)->ra;
		(*route)->rb -= (*route)->ra;
		(*route)->ra = 0;
	}
	if ((*route)->ra > -1 && (*route)->rb > -1 && (*route)->ra > (*route)->rb)
	{
		(*route)->rr = (*route)->rb;
		(*route)->ra -= (*route)->rb;
		(*route)->rb = 0;
	}
	if ((*route)->rra > -1 && (*route)->rrb > -1
		&& (*route)->rra <= (*route)->rrb)
	{
		(*route)->rrr = (*route)->rra;
		(*route)->rrb -= (*route)->rra;
		(*route)->rra = 0;
	}
	if ((*route)->rra > -1 && (*route)->rrb > -1
		&& (*route)->rra > (*route)->rrb)
	{
		(*route)->rrr = (*route)->rrb;
		(*route)->rra -= (*route)->rrb;
		(*route)->rrb = 0;
	}
}

static void	laying_routes(t_candidate **candidate, t_route **route, int i, int j)
{
	if (j == 0 && (*candidate)->nrb > -1)
		(*route)->rb = (*candidate)->nrb;
	if (j == 1 && (*candidate)->nrrb > -1)
		(*route)->rrb = (*candidate)->nrrb;
	if (i == 0 && (*candidate)->nra > -1)
		(*route)->ra = (*candidate)->nra;
	if (i == 1 && (*candidate)->nrra > -1)
		(*route)->rra = (*candidate)->nrra;
	double_moves(candidate, route);
	count_moves(route);
}

static t_route	*map_routes(t_candidate **c, t_route *route, int i, int j)
{
	t_route	*p;

	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			p = init_route(route);
			if (!p)
				return (0);
			route = p;
			laying_routes(c, &route, i, j);
		}
	}
	return (route);
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

	// printf("[Best route]\n");
	// printf("%d / %d / %d / %d / %d / %d / %d /\n",
	// 	p->operations,
	// 	p->ra,
	// 	p->rra,
	// 	p->rb,
	// 	p->rrb,
	// 	p->rr,
	// 	p->rrr
	// );
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
	return (clear_routes(&route, 1));
}
