/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:03:11 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 13:00:01 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	debug_candidates(t_candidate **c)
{

	printf("[debug_candidates]\n");
	*c = candidate_rewind(*c);
	while (*c)
	{
		printf("debug_candidates: %d / %d / %d / %d / %d / %d / %d\n", 
		(*c)->index,
		(*c)->position,
		(*c)->destination,
		(*c)->nra,
		(*c)->nrra,
		(*c)->nrb,
		(*c)->nrrb
		);
		if (!(*c)->next)
			break ;
		*c = (*c)->next;
	}
}

void	debug_routes(t_route **route)
{
	*route = route_rewind(*route);

	printf("[debug_route]\n");
	while (*route)
	{
		printf("debug_route: %d / %d / %d / %d / %d / %d / %d\n",
			(*route)->operations,
			(*route)->ra,
			(*route)->rra,
			(*route)->rb,
			(*route)->rrb,
			(*route)->rr,
			(*route)->rrr
		);
		if (!(*route)->next)
			break ;
		*route = (*route)->next;
	}
}

void	debug_stacks(t_stack *a, t_stack *b)
{
	printf("\n----------------\n\n***A STACK ***\n");
	if (a)
	{
		a = lst_rewind(a);
		while (a)
		{
			printf("%d > %d\n", a->index, a->content);
			if (!a->next)
				break ;
			a = a->next;
		}
		a = lst_rewind(a);
	}
	printf("***B STACK ***\n");
	if (b)
	{
		b = lst_rewind(b);
		while (b)
		{
			printf("%d > %d\n", b->index, b->content);
			if (!b->next)
				break ;
			b = b->next;
		}
		b = lst_rewind(b);
	}
	printf("\n----------------\n\n");
}