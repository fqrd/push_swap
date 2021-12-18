/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:52:01 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 15:59:34 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_route	*init_route(void)
{
	t_route *route;

	route = malloc(sizeof(t_route) * 1);
	if (!route)
		return (NULL);
	route->ra = 0;
	route->rra = 0;
	route->rb = 0;
	route->rrb = 0;
	route->rr = 0;
	route->rrr = 0;
	return (route);
}

static void	get_route(t_candidate **candidate, t_route **route)
{
	(*route)->nrx = (*candidate)->nra + (*candidate)->nrrb;
	(*route)->nrrx = (*candidate)->nrra + (*candidate)->nrb;
	(*route)->nrr = (*candidate)->nra;
	if ((*candidate)->nra < (*candidate)->nrb)
		(*route)->nrr = (*candidate)->nrb;
	(*route)->nrrr = (*candidate)->nrra;
	if ((*candidate)->nrra < (*candidate)->nrrb)
		(*route)->nrrr = (*candidate)->nrrb;
	printf("fastest?: nrx: %d / nrrx: %d / nrr: %d / nrrr: %d\n",
	(*route)->nrx, (*route)->nrrx, (*route)->nrr, (*route)->nrrr);
}

int	find_route(t_stack **a, t_stack **b, t_context **context, t_candidate **top, t_candidate **btm)
{
	t_route *route_top;
	t_route *route_btm;

	route_top = init_route();
	if (!route_top)
		return (0);
	route_btm = init_route();
	if (!route_btm)
		return (0);
	get_route(top, &route_top);
	get_route(btm, &route_btm);
	return (1);
}
