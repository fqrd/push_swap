/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:52:01 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/19 15:35:00 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	init_route(t_route **previous)
{
	t_route	*route;

	route = malloc(sizeof(t_route) * 1);
	if (!route)
		return (0);
	route->operations = 0;
	route->ra = -1;
	route->rra = -1;
	route->rb = -1;
	route->rrb = -1;
	route->rr = -1;
	route->rrr = -1;
	route->previous = *previous;
	if (*previous)
		(*previous)->next = route;
	route->next = NULL;
	*previous = route; 
	return (1);
}

static t_route	*route_rewind(t_route *lst)
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

static int	clear_routes(t_route **route, int value)
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
	return (value);
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

static int	map_routes(t_candidate **candidate, t_route **route, int i, int j)
{
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			if (!init_route(route))
				return (clear_routes(route, 0));
			if ((*route)->next)
				*route = (*route)->next;
			laying_routes(candidate, route, i, j);
		}
	}
	return (1);
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

int	find_and_apply_route(t_stack **a, t_stack **b, t_candidate **top,
	t_candidate **btm)
{
	t_route	*route;

	route = NULL;
	if (!map_routes(top, &route, -1, -1))
		return (0);
	if (!map_routes(btm, &route, -1, -1))
		return (0);
	apply_route(best_route(&route), a, b);
	return (clear_routes(&route, 1));
}
