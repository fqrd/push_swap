/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/21 19:42:00 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	conclude(t_stack **a, t_stack **b, t_context **context)
{
	int	position;

	position = get_position(b, (*context)->highestb);
	if (position > (int)(*context)->limitb)
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
	return (1);
}

static int	sort(t_stack **a, t_stack **b, t_context **context,
	t_candidate *c)
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
			if (!navigate(a, b, &c))
				return (clear_candidates(&c, 0));
			sort(pb(a, b, 0), b, context, NULL);
		}
		else
		{
			if (!navigate(a, b, &c))
				return (clear_candidates(&c, 0));
			sort(pb(a, b, 0), b, context, NULL);
		}
	}
	else
		return (conclude(a, b, context));
	return (1);
}

int	sort_big(t_stack **a, t_stack **b)
{
	t_context	*context;
	int			res;

	context = init_context();
	if (!context)
		return (0);
	res = sort(a, b, &context, NULL);
	free(context);
	return (res);
}
