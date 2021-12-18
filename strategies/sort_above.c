/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/18 23:42:03 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	back_to_a(t_stack **a, t_stack **b, t_context **context)
{
	int position;

	position = get_index_position(b, (*context)->highestb);
	if (position > (*context)->limitb)
	{
		while ((*context)->sizeb - position++ > 0)
			rrb(b);
	}
	else
	{
		while (position-- > 0)
			rb(b);
	}
	while ((*context)->sizeb-- > 0)
		pa(a, b, 0);		
}

static int	sort_above(t_stack **a, t_stack **b, t_context **context, t_candidate **top, t_candidate **btm)
{
	// display_stacks(*a, *b);
	context_reset(a, b, context);
	candidate_reset(top);
	candidate_reset(btm);
	*a = lst_rewind(*a);
	*b = lst_rewind(*b);

	if ((*context)->sizea > 0)
	{
		find_candidate(a, context, top, btm);
		find_destination(b, top, btm, context);
		// printf("[TOP] index: %d / nra: %d / nrra: %d / nrb: %d / nrrb: %d / position: %d\n", (*top)->index, (*top)->nra, (*top)->nrra, (*top)->nrb, (*top)->nrrb, (*top)->position);
		// printf("[BTM] index: %d / nra: %d / nrra: %d / nrb: %d / nrrb: %d / position: %d\n", (*btm)->index, (*btm)->nra, (*btm)->nrra, (*btm)->nrb, (*btm)->nrrb, (*btm)->position);
		if ((*context)->sizeb > 1)
		{
			find_and_apply_route(a, b, context, top, btm);
			(*context)->pushed_inc++;
			sort_above(pb(a, b, 0), b, context, top, btm);
		}
		else
		{
			find_and_apply_route(a, b, context, top, btm);
			(*context)->pushed_inc++;
			sort_above(pb(a, b, 0), b, context, top, btm);
		}
	}
	else
	{
		// go to highest *b
		back_to_a(a, b, context);
		return (1);
	}
    return (0);
}

static int	error_free(t_context *context, t_candidate *top, t_candidate *btm, int value)
{
	if (context)
		free(context);
	if (top)
		free(top);
	if (btm)
		free(btm);
	return (value);
}

int sort_above_entry(t_stack **a, t_stack **b)
{
	t_context *context;
	t_candidate *top;
	t_candidate *btm;

	context = init_context();
	if (!context)
		return (error_free(context, top, btm, 0));
	top = init_candidate();
	if (!top)
		return (error_free(context, top, btm, 0));
	btm = init_candidate();
	if (!btm)
		return (error_free(context, top, btm, 0));
	sort_above(a, b, &context, &top, &btm);
	return (error_free(context, top, btm, 1));
}
