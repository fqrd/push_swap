/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/17 23:56:35 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_obj	*init_obj(void)
{
	t_obj *obj;

	obj = malloc(sizeof(t_obj) * 1);
	if (!obj)
		return (NULL);
	obj->limita = 0;
	obj->limitb = 0;
	obj->sizea = 0;
	obj->sizeb = 0;
	obj->positiona = 0;
	obj->positionb = 0;
	obj->actions = 0;
	obj->firsta = NULL;
	obj->lasta = NULL;
	obj->firstb = NULL;
	obj->lastb = NULL;
	obj->group_size = 0;
	obj->group_inc = 0;
	obj->pushed_inc = 0;
	obj->highestb = 0; 
	obj->lowestb = 0;

	return (obj);
}

static t_route	*init_route(void)
{
	t_route *route;

	route = malloc(sizeof(t_route) * 1);
	if (!route)
		return (NULL);
	route->candidate_ra_destination = -1;
	route->candidate_ra_index = -1;
	route->candidate_ra_position = -1;
	route->candidate_rra_destination = -1;
	route->candidate_ra_rb = -1;
	route->candidate_ra_rrb = -1;
	route->candidate_rra_index = -1;
	route->candidate_rra_position = -1;
	route->candidate_rra_rb = -1;
	route->candidate_rra_rrb = -1;
	route->rr = -1;
	route->rrr = -1;
	return (route);
}

static void high_low(t_stack **b, t_obj **obj)
{
	size_t i;

	i = 0;
	*b = lst_rewind(*b);
	while (*b)
	{
		if (i == 0)
		{
			(*obj)->highestb = (*b)->index;
			(*obj)->lowestb = (*b)->index;
		}
		else
		{
			if ((*b)->index > (*obj)->highestb)
				(*obj)->highestb = (*b)->index;
			if ((*b)->index < (*obj)->lowestb)
				(*obj)->lowestb = (*b)->index;
		}
		if(!(*b)->next)
			break;
		*b = (*b)->next;
		i++;
	}
}

static void print_route(t_route **route, t_obj **obj)
{
	printf("ra: %d[%d] -> %d / rra: %d[%d] -> %d/ rr: %d/ rrr: %d/ group: %d\n", 
		(*route)->candidate_ra_position, (*route)->candidate_ra_index, (*route)->candidate_ra_destination,(*route)->candidate_rra_position, (*route)->candidate_rra_index, (*route)->candidate_rra_destination, (*route)->rr, (*route)->rrr, (*obj)->group_inc);
}

/* static void over_and_out(t_stack **a, t_stack **b, t_obj **obj)
{
	size_t	count;


	printf("over and out\n");

	count = find_highest(*b);
	if (count > 0 && count > (*obj)->limitb)
	{
		while (((*obj)->sizeb - ++count) < (*obj)->sizeb)
		{
			(*obj)->actions++;
			rrb(b);
		}
	}
	printf("double check 0: %zu\n", count);
	if (count > 0 && count <= (*obj)->limitb)
	{
		while (count-- > 0)
		{
			(*obj)->actions++;
			rb(b);
		}
	}
	while (*b)
	{
		(*obj)->actions++;
		pa(a, b, 0);
		if (!(*b)->next)
		{
			(*obj)->actions++;
			pa(a, b, 0);
			break;
		}
		*b = (*b)->next;
	}
}
*/

static void	fill_obj(t_stack **a, t_stack **b, t_obj **obj)
{
	(*obj)->sizea = lst_size(*a);
	(*obj)->sizeb = lst_size(*b);
	(*obj)->limita = ((*obj)->sizea / 2) + 1;
	(*obj)->limitb = ((*obj)->sizeb / 2) + 1;
	(*obj)->firsta = lst_rewind(*a);
	(*obj)->lasta = lst_forward(*a);
	(*obj)->firstb = lst_rewind(*b);
	(*obj)->lastb = lst_forward(*b);

	high_low(b, obj);
	
	(*obj)->group_size = 10;
	(*obj)->pushed_inc = 0;
	(*obj)->group_inc = (((*obj)->pushed_inc / (*obj)->group_size) + 1) * (*obj)->group_size;

	if ((*obj)->sizea > 0)
		printf("sizea: %zu / limita: %zu / firsta: %d / lasta: %d\n", 
			(*obj)->sizea, (*obj)->limita, (*obj)->firsta->index, (*obj)->lasta->index);
	if ((*obj)->sizeb > 0)
		printf("sizeb: %zu / limitb: %zu / firstb: %d / lastb: %d / highest: %d/ lowest: %d\n", 
			(*obj)->sizeb, (*obj)->limitb, (*obj)->firstb->index, (*obj)->lastb->index, (*obj)->highestb, (*obj)->lowestb);
}

/* static void	move_stacks(t_stack **a, t_stack **b, t_route **route, t_obj **obj)
{
	size_t i;

	i = 0;
	if ((*route)->moves_b > 0)
	{
		if ((*route)->moves_b > (*obj)->limitb)
		{
			// consider rrb
		}
	}
	if ((*route)->ra <= (*route)->rra && (*route)->ra > 0)
	{
		while (i++ < (*route)->ra)
			ra(a);
	}
	else
	{
		while (i++ < (*route)->rra)
			rra(a);
	}
}
*/

static void	find_route(t_stack **a, t_stack **b, t_route **route, t_obj **obj)
{
	(*route)->candidate_ra_rb = (*route)->candidate_ra_destination;
	(*route)->candidate_ra_rrb = ((*obj)->sizeb - (*route)->candidate_ra_destination);
	(*route)->candidate_rra_rb = (*route)->candidate_rra_destination;
	(*route)->candidate_rra_rrb = ((*obj)->sizeb - (*route)->candidate_rra_destination);

	printf("\n*********\n");
	if ((*route)->candidate_ra_position < (*route)->candidate_ra_rb)
	{
		(*route)->rr = (*route)->candidate_ra_rb - ((*route)->candidate_ra_rb - (*route)->candidate_ra_position);
		printf("fastest 1? rr: %d\n", (*route)->candidate_ra_rb);
	}
	else
	{
		(*route)->rr = (*route)->candidate_ra_position - ((*route)->candidate_ra_position - (*route)->candidate_ra_rb);
		printf("fastest 2? rr: %d\n", (*route)->candidate_ra_position);
	}

	if ((*route)->candidate_rra_position < (*route)->candidate_rra_rrb)
	{
		(*route)->rrr = (*route)->candidate_rra_rrb - ((*route)->candidate_rra_rrb - (*route)->candidate_rra_position);
		printf("fastest 1? rrr: %d\n", (*route)->candidate_rra_rrb);
	}
	else
	{
		(*route)->rrr = (*route)->candidate_rra_position - ((*route)->candidate_rra_position - (*route)->candidate_rra_rrb);
		printf("fastest 2? rrr: %d\n", (*route)->candidate_rra_rrb);
	}


	printf("\n*********\n");
	printf("candidate ra index: %d\n",(*route)->candidate_ra_index);
	printf("candidate ra destination: %d\n",(*route)->candidate_ra_destination);
	printf("candidate ra position: %d\n",(*route)->candidate_ra_position);
	printf("candidate ra rb: %d\n",(*route)->candidate_ra_rb);
	printf("candidate ra rrb: %d\n",(*route)->candidate_ra_rrb);
	printf("\n*********\n");
	printf("candidate rra index: %d\n",(*route)->candidate_rra_index);
	printf("candidate rra destination: %d\n",(*route)->candidate_rra_destination);
	printf("candidate rra position: %d\n",(*route)->candidate_rra_position);
	printf("candidate rra rb: %d\n",(*route)->candidate_rra_rb);
	printf("candidate rra rrb: %d\n",(*route)->candidate_rra_rrb);
	printf("\n*********\n");
	printf("rr: %d\n", (*route)->rr);
	printf("rrr: %d\n", (*route)->rrr);
	printf("\n*********\n");
	printf("\n*********\n");

}

static int	sort_above(t_stack **a, t_stack **b, t_obj **obj, t_route **route)
{
	// int group;

	display_stacks(*a, *b);
	fill_obj(a, b, obj);

	*a = lst_rewind(*a);
	*b = lst_rewind(*b);


	// group = (*obj)->group_size * (*obj)->group_inc;

	if ((*obj)->sizea > 0)
	{
		// find candidate
		find_candidate(a, route, obj);
		printf("candidates: ra: %d[%d] / rra: %d[%d]\n", (*route)->candidate_ra_position, (*route)->candidate_ra_index, (*route)->candidate_rra_position, (*route)->candidate_rra_index);

		// best route to get candidate on top of stack a
		// #don't move a yet, wait to know where the a number goes in be
		// #maybe you'd be able to use rr or rrr to use less actions
		// find best opening *b
		// best route to get there

		if ((*obj)->sizeb > 1)
		{
			printf("IF\n");
			find_destination(b, route, obj);
			// get best route first !
			print_route(route, obj);
			find_route(a, b, route, obj);
			pb(a, b, 0);
			sort_above(a, b, obj, route);
		}
		else
		{
			printf("ELSE\n");

			// get best route first !
			print_route(route, obj);
			find_route(a, b, route, obj);
			pb(a, b, 0);
			sort_above(a, b, obj, route);
			// sort_above(pb(a, b, 0), b, obj, route);
		}

		// move stacks
		// move_stacks(a, b, route);
		
		// push to b
		// pb(a, b, 0);
		
		// increment (*obj)->pushed_inc
		/*
		if ((*obj)->pushed_inc >= (*obj)->group_size)
		{
			(*obj)->group_inc++;
			(*obj)->pushed_inc = 0;
		}
		*/
	}
	else
	{
		// go to highest *b
		printf("SHOULD BE SORTED: RETURN TO B\n");
		return (1);
	}
    return (0);
}

int sort_above_entry(t_stack **a, t_stack **b)
{
	t_obj *obj;
	t_route *route;

	obj = init_obj();
	if (!obj)
		return (0);
	route = init_route();
	if (!route)
		return (0);
	sort_above(a, b, &obj, &route);
	free (obj);
	free (route);
	return (1);
}
