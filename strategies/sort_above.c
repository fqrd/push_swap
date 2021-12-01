/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/01 18:39:45 by fcaquard         ###   ########.fr       */
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
	a->firsta = NULL;
	a->lasta = NULL;
	a->firstb = NULL;
	a->lastb = NULL;
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
		}
		if (!x->next)
			break;
		x = x->next;
	}
	x = lst_rewind(x);
	// printf("Highest: %zu\n", count);
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

	// if (x)
		// printf("find_opening x->index: %d / index: %d\n", x->index, index);

	// if (index > highest)

	// else if (index < lowest)

	// else
	// {

	// }
	while (x)
	{
		i++;
		if (x->index < index && ((index - x->index < k) || k == 0))
		{
			count = i;
			k = index - x->index;
			// printf("diff: %d / place: %zu /  x->index: %d / index: %d / position: BEFORE %d\n", k, i, x->index, index, x->index);
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

	if ((*obj)->sizea > 0)
		printf("sizea: %zu / limita: %zu / firsta: %d / lasta: %d\n", (*obj)->sizea, (*obj)->limita, (*obj)->firsta->index, (*obj)->lasta->index);
	if ((*obj)->sizeb > 0)
		printf("sizeb: %zu / limitb: %zu / firstb: %d / lastb: %d\n", (*obj)->sizeb, (*obj)->limitb, (*obj)->firstb->index, (*obj)->lastb->index);

}

static void	send_to_b(t_stack **b, t_obj **obj, size_t place)
{
	// printf("place: %zu / limit: %zu / sizeb: %zu\n", place, (*obj)->limitb, (*obj)->sizeb);
	int	i;

	i = 0;
	if (place > 1)
	{
		if (place > (*obj)->limitb)
		{
			while (i <  (int)((*obj)->sizeb - place) + 1)
			{
				// printf("second half\n");
				(*obj)->actions++;
				rrb(b);
				i++;
			}
		}
		else
		{
			while (--place > 0)
			{
				// printf("first half\n");
				(*obj)->actions++;
				rb(b);
			}
		}
	}
}

// static void	return_to_a()
// {

// }


int	sort_above(t_stack **a, t_stack **b, t_obj **obj)
{
	// size_t	count;

	fill_obj(a, b, obj);

	*a = lst_rewind(*a);
	*b = lst_rewind(*b);

	// getchar();

	// if (lst_is_kinda_sorted_a(*a, *obj))
	// {
	// 	printf("A IS SORTED, well almost.\n");
	// }
	// if (lst_is_kinda_sorted_b(*b, *obj))
	// {
	// 	printf("B IS SORTED, well almost.\n");
	// }

	if (lst_is_kinda_sorted_a(*a, *obj) && lst_is_kinda_sorted_b(*b, *obj))
	{
		printf ("total: %zu\n", (*obj)->actions);
		return (0);
	}

	// display_stacks(*a, *b);
    if ((*obj)->sizea > 0)
    {
		// (*obj)->positiona = find_opening(*a, (*a)->index);
		// if ((*obj)->positiona == 0)
		// 	(*obj)->positiona = find_highest(*a);
		// (*obj)->positionb = find_opening(*b, (*a)->index);
		// if ((*obj)->positionb == 0)
		// 	(*obj)->positionb = find_highest(*b);
		// count = (*obj)->positionb;


		// printf("positiona: %zu / positionb: %zu\n", (*obj)->positiona, (*obj)->positionb);

		if ((*obj)->sizea >= 3)
		{
			if ((*obj)->firsta->index > (*obj)->firsta->next->index
				&& (*obj)->firsta->next->index > (*obj)->lasta->index)
			{
				// printf("#1\n");
				(*obj)->actions += 2;
				sa(a);
				ra(a);
			}
			else if ((*obj)->sizea >= 4 
				&& (*obj)->firsta->index > (*obj)->lasta->previous->index
				&& (*obj)->lasta->index < (*obj)->firsta->next->index
				&& (*obj)->firsta->index < (*obj)->lasta->index)
			{
				printf("#2\n");
				(*obj)->actions += 2;
				rra(a);
				sa(a);
			}
			else if ((*obj)->firsta->index > (*obj)->lasta->index
				&& (*obj)->firsta->next->index < (*obj)->lasta->index)
			{
				// printf("#4\n");
				(*obj)->actions++;
				ra(a);
			}
			else if ((*obj)->sizea >= 4
				&& (*obj)->firsta->index < (*obj)->firsta->next->index
				&& (*obj)->firsta->index < (*obj)->lasta->index
				&& (*obj)->firsta->index < (*obj)->lasta->previous->index)
			{
				// printf("#3\n");
				/*
				PUSH AT THE RIGHT PLACE IN B
				*/
				(*obj)->positionb = find_opening(*b, (*a)->index);
				if ((*obj)->positionb == 0)
					(*obj)->positionb = find_highest(*b);
				send_to_b(b, obj, (*obj)->positionb);
				pb(a, b, 0);
			}
			else if ((*obj)->firsta->index < (*obj)->lasta->index
				&& (*obj)->firsta->index > (*obj)->firsta->next->index)
			{
				// printf("#5\n");
				/*
				PUSH AT THE RIGHT PLACE IN B
				*/
				(*obj)->positionb = find_opening(*b, (*a)->index);
				if ((*obj)->positionb == 0)
					(*obj)->positionb = find_highest(*b);
				send_to_b(b, obj, (*obj)->positionb);
				pb(a, b, 0);
			}
			else
			{
				// printf("#ELSE\n");
				(*obj)->actions++;
				ra(a);
			}
			sort_above(a, b, obj);
		}
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
