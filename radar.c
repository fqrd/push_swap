/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:52:01 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 20:06:00 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_route	*init_route(t_route *previous)
{
	t_route *route;

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

static void	map_routes(t_candidate **candidate, t_route **route)
{
	int i;
	int j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			*route = init_route(*route);
			if (j == 0 && (*candidate)->nrb > -1)
			{
				(*route)->rb = (*candidate)->nrb;
				(*route)->operations += (*candidate)->nrb;
			}
			if (j == 1 && (*candidate)->nrrb > -1)
			{
				(*route)->rrb = (*candidate)->nrrb;
				(*route)->operations += (*candidate)->nrrb;
			}
			if (i == 0 && (*candidate)->nra > -1)
			{
				(*route)->ra = (*candidate)->nra;
				(*route)->operations += (*candidate)->nra;
			}
			if (i == 1 && (*candidate)->nrra > -1)
			{
				(*route)->rra = (*candidate)->nrra;
				(*route)->operations += (*candidate)->nrra;
			}
			j++;
		}
		i++;
	}
}

static void	compare_routes(t_context **context, t_route **route_top, t_route **route_btm)
{
	printf("COMPARING\n");
	// int lowest;
	// int option;

	// lowest = (*route_top)->nrx;
	// if ((*route_top)->nrr < lowest)
	// 	lowest = (*route_top)->nrr;
	// if ((*route_top)->nrrx < lowest)
	// 	lowest = (*route_top)->nrrx;
	// if ((*route_top)->nrrr < lowest)
	// 	lowest = (*route_top)->nrrr;
	// if ((*route_btm)->nrx < lowest)
	// 	lowest = (*route_btm)->nrx;
	// if ((*route_btm)->nrr < lowest)
	// 	lowest = (*route_btm)->nrr;
	// if ((*route_btm)->nrrx < lowest)
	// 	lowest = (*route_btm)->nrrx;
	// if ((*route_btm)->nrrr < lowest)
	// 	lowest = (*route_btm)->nrrr;
}

int	find_route(t_context **context, t_candidate **top, t_candidate **btm)
{
	t_route *route;

	route = NULL;
	map_routes(top, &route);
	printf("\n---------------------\n");
	map_routes(btm, &route);

	route = route_rewind(route);
	
	while (route)
	{
		printf("op: %d / ra: %d / rra: %d / rb: %d / rrb: %d / rr: %d / rrr: %d\n",
		route->operations,
		route->ra,
		route->rra,
		route->rb,
		route->rrb,
		route->rr,
		route->rrr
		);
		if (!route->next)
			break;
		route = route->next;
	}
	return (1);
}
