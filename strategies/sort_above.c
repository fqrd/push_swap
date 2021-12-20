/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 14:28:24 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	back_to_a(t_stack **a, t_stack **b, t_context **context)
{
	int	position;

	position = get_position(b, (*context)->highestb);
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

static int	sort_above(t_stack **a, t_stack **b, t_context **context, t_candidate *c)
{
	context_reset(a, b, context);
	*a = lst_rewind(*a);
	*b = lst_rewind(*b);
	if ((*context)->sizea > 0)
	{
		c = find_candidates(a, context, c);
		find_destination(b, &c, context);

		if ((*context)->sizeb > 1)
		{
			if (!find_and_apply_route(a, b, &c))
				return (clear_candidates(&c, 0));
			(*context)->pushed_inc++;
			sort_above(pb(a, b, 0), b, context, NULL);
		}
		else
		{
			if (!find_and_apply_route(a, b, &c))
				return (clear_candidates(&c, 0));
			(*context)->pushed_inc++;
			sort_above(pb(a, b, 0), b, context, NULL);
		}
	}
	else
	{
		back_to_a(a, b, context);
		return (1);
	}
	return (1);
}

static int	error_free(t_context *context, int value)
{
	if (context)
		free(context);
	return (value);
}

int	sort_above_entry(t_stack **a, t_stack **b)
{
	t_context	*context;
	t_candidate	*c;

	c = NULL;
	context = init_context(*a);
	if (!context)
		return (error_free(context, 0));
	if (!sort_above(a, b, &context, c))
		return (error_free(context, 0));
	return (error_free(context, 1));
}
