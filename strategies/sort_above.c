/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/25 13:38:16 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_obj	*create_obj(void)
{
	t_obj *a;

	a = malloc(sizeof(t_obj) * 1);
	if (!a)
		return (NULL);
	a->limita = 0;
	a->limitb = 0;
	a->sizea = 0;
	a->sizeb = 0;
	a->positiona = 0;
	a->positionb = 0;
	a->actions = 0;
	return (a);
}

static size_t	find_highest(t_stack *x)
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
			// printf("ohk: %d\n", k);
		}
		if (!x->next)
			break;
		x = x->next;
	}
	x = lst_rewind(x);
	return (count);
}

static size_t	find_opening(t_stack *x, int index)
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
		if (x->index < index && ((index - x->index < k) || k == 0))
		{
			count = i;
			k = index - x->index;
			// printf("opk: %d\n", k);
		}
		if (!x->next)
			break;
		x = x->next;
	}
	x = lst_rewind(x);
	return (count);
}

/*
static int	closest_action(t_obj *obj)
{
	size_t dista;
	size_t distb;

	dista = obj->positiona; 
	distb = obj->positionb;	
	if (obj->positiona > obj->limita)
		dista = obj->positiona - obj->limita;
	if (obj->positionb > obj->limitb)
		dista = obj->positionb - obj->limitb;
	return (dista <= distb);
}
*/



static void over_and_out(t_stack **a, t_stack **b, t_obj **obj)
{
	size_t	count;

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

int	sort_above(t_stack **a, t_stack **b, t_obj **obj)
{
	size_t	count;

	(*obj)->sizea = lst_size(*a);
	(*obj)->sizeb = lst_size(*b);
	(*obj)->limita = ((*obj)->sizea / 2) + 1;
	(*obj)->limitb = ((*obj)->sizeb / 2) + 1;

	display_stacks(*a, *b);
    if (lst_size(*a) > 0)
    {
		(*obj)->positiona = find_opening(*a, (*a)->index);
		if ((*obj)->positiona == 0)
			(*obj)->positiona = find_highest(*a);
		(*obj)->positionb = find_opening(*b, (*a)->index);
		if ((*obj)->positionb == 0)
			(*obj)->positionb = find_highest(*b);
		count = (*obj)->positionb;
		// printf("count: %zu / limit: %lu / sizeb; %zu\n", count, (sizeb / 2) + 1, sizeb);
		if (count > 0)
		{
			if (count > (*obj)->limitb)
			{
				while (((*obj)->sizeb - ++count) < (*obj)->sizeb)
				{
					// printf("second half\n");
					(*obj)->actions++;
					rrb(b);
				}
			}
			else
			{
				while (count-- > 0)
				{
					// printf("first half\n");
					(*obj)->actions++;
					rb(b);
				}
			}
		}
		(*obj)->actions++;
		sort_above(pb(a, b, 0), b, obj);
    }
	else
	{
		over_and_out(a, b, obj);
		printf ("total: %zu\n", (*obj)->actions);
		return (1);
	}
    return (0);
}

void sort_above_entry(t_stack **a, t_stack **b)
{
	t_obj *obj;
	
	obj = create_obj();
	sort_above(a, b, &obj);
	free (obj);
}
