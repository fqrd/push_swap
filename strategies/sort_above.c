/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/25 11:34:08 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static	size_t	find_biggest(t_stack **x)
// {
// 	size_t	index;

// 	index = 0;
// 	x = lst_rewind(x);
// 	while (index )


// 	return (index);
// }


static	size_t	find_highest(t_stack *b)
{
	size_t count;
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	count = 0;
	b = lst_rewind(b);
	while (b)
	{
		if (b->index > k)
		{
			count = i;
			k = b->index;
			// printf("ohk: %d\n", k);
		}
		if (!b->next)
			break;
		b = b->next;
		i++;
	}
	return (count);
}


static size_t	find_opening(t_stack *b, int index)
{
	size_t count;
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	count = 0;
	while (b)
	{
		if (b->index < index && ((index - b->index < k) || k == 0))
		{
			count = i;
			k = index - b->index;
			// printf("opk: %d\n", k);
		}
		if (!b->next)
			break;
		b = b->next;
		i++;
	}
	return (count);
}

int sort_above(size_t args, t_stack **a, t_stack **b)
{
    size_t          count;
	size_t			sizeb;

    count = 0;
	*b = lst_rewind(*b);
	sizeb = lst_size(*b);
	// display_stacks(*a, *b);

    if (lst_size(*a) > 0)
    {
		count = find_opening(*b, (*a)->index);
		if (count == 0)
			count = find_highest(*b);
		// printf("count: %zu / limit: %lu / sizeb; %zu\n", count, (sizeb / 2) + 1, sizeb);

		if (count > 0)
		{
			if (count > (sizeb / 2) + 1)
			{
				while ((sizeb - ++count) < sizeb)
				{
					// printf("second half\n");
					rrb(b);
				}
			}
			else
			{
				while (count-- > 0)
				{
					// printf("first half\n");
					rb(b);
				}
			}
		}
		sort_above(args, pb(a, b, 0), b);
    }
	else
	{
		count = find_highest(*b);
		if (count > 0)
		{
			if (count > (sizeb / 2) + 1)
			{
				while ((sizeb - ++count) < sizeb)
				{
					// printf("second half\n");
					rrb(b);
				}
			}
			else
			{
				while (count-- > 0)
				{
					// printf("first half\n");
					rb(b);
				}
			}
		}
		*b = lst_rewind(*b);
		while (*b)
		{
			pa(a, b, 0);
			if (!(*b)->next)
			{
				pa(a, b, 0);
				break;
			}
			*b = (*b)->next;
		}
		return (1);
	}
    return (0);
}