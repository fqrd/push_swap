/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:17:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/24 16:27:35 by fcaquard         ###   ########.fr       */
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



static size_t	find_opening(t_stack *b, int index)
{
	int k;
	int o;
	size_t	i;
	size_t	count;
	
	o = 0;
	i = 0;
	k = 0;
	count = 0;
	while (b)
	{
		i++;

		o = (index - b->index);
		if (o < 0)
			o *= (-1);
		if (k == 0 || o <= k)
		{
			k = o;
			count = i;
		}
		if (!b->next)
			break;
		b = b->next;
	}
	return (count);
}

int sort_above(size_t args, t_stack **a, t_stack **b)
{
    size_t          count;

    count = 0;
	*b = lst_rewind(*b);
	// display_stacks(*a, *b);

    if (lst_size(*a) > 0)
    {
		count = find_opening(*b, (*a)->index);
		// printf("count: %zu\n", count);

		*b = lst_rewind(*b);
		if (count > 1)
		{
			if (count > (args / 2) + 1)
			{
				while ((args - count--) < args)
				{
					// printf("second half\n");
					rrb(b);
				}
			}
			else
			{
				while (count-- > 1)
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
		// find highest and move it to the top
	}
        // if (lst_size(*a) == 0)
        // {
        //     while (*b)
        //     {
        //         pa(a, b, 0);
        //         if (!(*b)->next)
        //             break;
        //         *b = (*b)->next;
        //     }
        //     return (1);
        // }


    return (0);
}