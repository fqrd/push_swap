/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:41:54 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:50:38 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	operations(t_route **route)
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

static void	rr_rrr(t_route **r)
{
	if ((*r)->ra > -1 && (*r)->rb > -1 && (*r)->ra <= (*r)->rb)
	{
		(*r)->rr = (*r)->ra;
		(*r)->rb -= (*r)->ra;
		(*r)->ra = 0;
	}
	if ((*r)->ra > -1 && (*r)->rb > -1 && (*r)->ra > (*r)->rb)
	{
		(*r)->rr = (*r)->rb;
		(*r)->ra -= (*r)->rb;
		(*r)->rb = 0;
	}
	if ((*r)->rra > -1 && (*r)->rrb > -1 && (*r)->rra <= (*r)->rrb)
	{
		(*r)->rrr = (*r)->rra;
		(*r)->rrb -= (*r)->rra;
		(*r)->rra = 0;
	}
	if ((*r)->rra > -1 && (*r)->rrb > -1 && (*r)->rra > (*r)->rrb)
	{
		(*r)->rrr = (*r)->rrb;
		(*r)->rra -= (*r)->rrb;
		(*r)->rrb = 0;
	}
}

static void	draw_routes(t_candidate **c,
	t_route **r, int i, int j)
{
	if (j == 0 && (*c)->nrb > -1)
		(*r)->rb = (*c)->nrb;
	if (j == 1 && (*c)->nrrb > -1)
		(*r)->rrb = (*c)->nrrb;
	if (i == 0 && (*c)->nra > -1)
		(*r)->ra = (*c)->nra;
	if (i == 1 && (*c)->nrra > -1)
		(*r)->rra = (*c)->nrra;
	rr_rrr(r);
	operations(r);
}

t_route	*map_routes(t_candidate **c, t_route *route, int i, int j)
{
	t_route	*p;

	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			p = init_route(route);
			if (!p)
			{
				clear_routes(&route);
				return (NULL);
			}
			route = p;
			draw_routes(c, &route, i, j);
		}
	}
	return (route);
}
