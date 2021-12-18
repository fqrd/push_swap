/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 12:02:52 by fcaquard         ###   ########.fr       */
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
	route->candidate_top_destination = -1;
	route->candidate_top_index = -1;
	route->candidate_top_position = -1;
	route->candidate_btm_destination = -1;
	route->candidate_top_rb = -1;
	route->candidate_top_rrb = -1;
	route->candidate_btm_index = -1;
	route->candidate_btm_position = -1;
	route->candidate_btm_rb = -1;
	route->candidate_btm_rrb = -1;
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
	printf("#print_route# ra: %d[%d] -> %d / rra: %d[%d] -> %d/ rr: %d/ rrr: %d/ group: %d\n", 
		(*route)->candidate_top_position, (*route)->candidate_top_index, (*route)->candidate_top_destination,
		(*route)->candidate_btm_position, (*route)->candidate_btm_index, (*route)->candidate_btm_destination,
		(*route)->rr, (*route)->rrr, (*obj)->group_inc);
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

	// if ((*obj)->sizea > 0)
	// 	printf("sizea: %zu / limita: %zu / firsta: %d / lasta: %d\n", 
	// 		(*obj)->sizea, (*obj)->limita, (*obj)->firsta->index, (*obj)->lasta->index);
	// if ((*obj)->sizeb > 0)
	// 	printf("sizeb: %zu / limitb: %zu / firstb: %d / lastb: %d / highest: %d/ lowest: %d\n", 
	// 		(*obj)->sizeb, (*obj)->limitb, (*obj)->firstb->index, (*obj)->lastb->index, (*obj)->highestb, (*obj)->lowestb);
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
	(*route)->candidate_top_rb = (*route)->candidate_top_destination;
	(*route)->candidate_top_rrb = ((*obj)->sizeb - (*route)->candidate_top_destination);
	(*route)->candidate_btm_rb = (*route)->candidate_btm_destination;
	(*route)->candidate_btm_rrb = ((*obj)->sizeb - (*route)->candidate_btm_destination);

	printf("\n*********\n");
	if ((*route)->candidate_top_position < (*route)->candidate_top_rb)
	{
		(*route)->rr = (*route)->candidate_top_rb - ((*route)->candidate_top_rb - (*route)->candidate_top_position);
		printf("fastest 1? rr + ra: %d\n", (*route)->candidate_top_rb);
	}
	else
	{
		(*route)->rr = (*route)->candidate_top_position - ((*route)->candidate_top_position - (*route)->candidate_top_rb);
		printf("fastest 2? rr + rb: %d\n", (*route)->candidate_top_position);
	}

	if ((*route)->candidate_btm_position < (*route)->candidate_btm_rrb)
	{
		(*route)->rrr = (*route)->candidate_btm_rrb - ((*route)->candidate_btm_rrb - (*route)->candidate_btm_position);
		printf("fastest 1? rrr + rra: %d\n", (*route)->candidate_btm_rrb);
	}
	else
	{
		(*route)->rrr = (*route)->candidate_btm_position - ((*route)->candidate_btm_position - (*route)->candidate_btm_rrb);
		printf("fastest 2? rrr + rrb: %d\n", (*route)->candidate_btm_rrb);
	}


	printf("\n*********\n");
	printf("candidate top index: %d\n",(*route)->candidate_top_index);
	printf("candidate top destination: %d\n",(*route)->candidate_top_destination);
	printf("candidate top position: %d\n",(*route)->candidate_top_position);
	printf("candidate top rb: %d\n",(*route)->candidate_top_rb);
	printf("candidate top rrb: %d\n",(*route)->candidate_top_rrb);
	printf("\n*********\n");
	printf("candidate btm index: %d\n",(*route)->candidate_btm_index);
	printf("candidate btm destination: %d\n",(*route)->candidate_btm_destination);
	printf("candidate btm position: %d\n",(*route)->candidate_btm_position);
	printf("candidate btm rb: %d\n",(*route)->candidate_btm_rb);
	printf("candidate btm rrb: %d\n",(*route)->candidate_btm_rrb);
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
		printf("candidates: ra: %d[%d] / rra: %d[%d]\n", 
			(*route)->candidate_top_position, (*route)->candidate_top_index, 
			(*route)->candidate_btm_position, (*route)->candidate_btm_index);

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
