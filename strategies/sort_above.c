/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/15 20:15:48 by fcaquard         ###   ########.fr       */
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
	return (obj);
}

static t_route	*init_route(void)
{
	t_route *route;

	route = malloc(sizeof(t_route) * 1);
	if (!route)
		return (NULL);
	route->ra = -1;
	route->ra_index = -1;
	route->rra = -1;
	route->rra_index = -1;
	route->rb = -1;
	route->rrb = -1;
	route->rr = -1;
	route->rrr = -1;
	return (route);
}

static t_state	*init_state(void)
{
	t_state *state;

	state = malloc(sizeof(t_state) * 1);
	if (!state)
		return (NULL);
	state->size = 0;
	state->highest = 0; 
	state->lowest = 0;
}

static void print_route(t_route **route, t_obj **obj)
{
	printf("ra: %ld/ rra: %ld/ rb: %ld/ rrb: %ld/ rr: %ld/ rrr: %ld/ group: %d\n", 
		(*route)->ra, (*route)->rra, (*route)->rb, (*route)->rrb, (*route)->rr, (*route)->rrr, (*obj)->group_inc);
}

/*static size_t	find_highest(t_stack *x)
{
	size_t count;
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	count = 0;
	x = lst_rewind(x);
	while (x)
	{
		i++;
		if (x->index > k)
		{
			count = i;
			k = x->index;
		}
		if (!x->next)
			break;
		x = x->next;
	}
	x = lst_rewind(x);
	// printf("Highest: %zu\n", count);
	return (count);
}
*/

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

	(*obj)->group_size = 10;
	(*obj)->pushed_inc = 0;
	(*obj)->group_inc = (((*obj)->pushed_inc / (*obj)->group_size) + 1) * (*obj)->group_size;

	if ((*obj)->sizea > 0)
		printf("sizea: %zu / limita: %zu / firsta: %d / lasta: %d\n", 
			(*obj)->sizea, (*obj)->limita, (*obj)->firsta->index, (*obj)->lasta->index);
	if ((*obj)->sizeb > 0)
		printf("sizeb: %zu / limitb: %zu / firstb: %d / lastb: %d\n", 
			(*obj)->sizeb, (*obj)->limitb, (*obj)->firstb->index, (*obj)->lastb->index);
}

static void	move_stacks(t_stack **a, t_stack **b, t_route **route)
{
	size_t i;

	i = 0;
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

static void	find_best_opening(t_stack **x, t_route **route, t_stack **obj)
{
	int index;
	size_t best;
	size_t i;
	size_t position;

	if ((*route)->ra <= (*route)->rra)
		index = (*route)->ra_index;
	else
		index = (*route)->rra_index;
	// if higher on stack. closest higher first, closest lower last
	// if index is highest. lowest first.
	// if index is lowest. highest first.

	// looking for highest;
	i = 0;
	*x = lst_rewind(*x);
	while (*x)
	{
		if (index - (*x)->index < best)
		{
			best = index - (*x)->index;
			position = i;
		}
		if (!(*x)->next)
			break;
		*x = (*x)->next;
	}

	// looking for lowest
	i = 0;
	*x = lst_rewind(*x);
	while (*x)
	{
		if (index - (*x)->index > best)
		{
			best = index - (*x)->index;
			position = i;
		}
		if (!(*x)->next)
			break;
		*x = (*x)->next;
	}
}

static void	find_closest_r(t_stack **x, t_route **route, t_obj **obj)
{
	size_t	i;

	i = 0;
	*x = lst_rewind(*x);
	while (*x)
	{
		if ((*x)->index <= (*obj)->group_inc)
		{
			printf("ra: %ld\n", i);
			(*route)->ra = i; 
			(*route)->ra_index = (*x)->index; 
			break;
		}
		if (!(*x)->next)
			break;
		*x = (*x)->next;
		i++;
	}
}

static void	find_closest_rr(t_stack **x, t_route **route, t_obj **obj)
{
	size_t	i;

	i = 1;
	*x = lst_forward(*x);
	printf("x->index: %d\n", (*x)->index);
	while (*x)
	{
		if ((*x)->index <= (*obj)->group_inc)
		{
			printf("rra: %ld\n", i);
			(*route)->rra = i; 
			(*route)->rra_index = (*x)->index; 
			break;
		}
		if (!(*x)->previous)
			break;
		*x = (*x)->previous;
		i++;
	}
}

static void find_candidate(t_stack **x, t_route **route, t_obj **obj)
{
	find_closest_r(x, route, obj);
	find_closest_rr(x, route, obj);
}

static int	sort_above(t_stack **a, t_stack **b, t_obj **obj, t_route **route, t_state **state_b)
{
	// int group;

	fill_obj(a, b, obj);
	// group = (*obj)->group_size * (*obj)->group_inc;

	if ((*obj)->sizea > 0)
	{
		// find candidate
		find_candidate(a, route, obj);

		// best route to get candidate on top of stack a
		// #don't move a yet, wait to know where the a number goes in be
		// #maybe you'd be able to use rr or rrr to use less actions
		// find best opening *b
		// best route to get there

		find_best_opening(a, route, obj);


		print_route(route, obj);
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
		printf("SHOULD BE SORTED: RETURN TO B");
		return (1);
	}
    return (0);
}

void sort_above_entry(t_stack **a, t_stack **b)
{
	t_obj *obj;
	t_route *route;
	t_state	*state_b;

	obj = init_obj();
	route = init_route();
	state_b = init_state();
	sort_above(a, b, &obj, &route, &state_b);
	free (obj);
	free (route);
}
