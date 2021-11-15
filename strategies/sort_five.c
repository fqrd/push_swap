/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:22:42 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 15:34:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"





int	sort_five(t_list **a, t_list **b)
{
	int a_size;
	int b_size;

	display_stacks(*a, *b);

	*a = lst_rewind(*a);
	*b = lst_rewind(*b);

	a_size = lst_size(*a);
	b_size = lst_size(*b);


	if (a_size == 5 && b_size == 0)
	{
		if (!lst_issorted(*a))
		{
			if ((*a)->index == 1 || (*a)->index == 2)
			{
				pb(a, b);
				sort_five(a, b);
			}
			else
			{
				if ((*a)->next && (((*a)->next->index == 1 || (*a)->next->index == 2)))
				{
					sort_five(ra(a), b);
				}
				if ((*a)->next && (*a)->next->next && 
					(((*a)->next->next->index == 1 || (*a)->next->next->index == 2)))
				{
					sort_five(ra(a), b);
				}
			}
		}
		else
		{
			return (1);
		}
	}
	else if(a_size == 4 && b_size == 1)
	{
		if (!lst_issorted(*a))
		{

		}
		else
		{
			pa(a, b);
			// sa(a);
			sort_five(a, b);
		}
	}
	else if(a_size == 3 && b_size == 2)
	{
		if (lst_issorted(*a) && lst_issorted(*b))
		{
			pa(a, b);
			pa(a, b);
			// sa(a);
			sort_five(a, b);
		}
		else
		{
			sort_three(a);
			sort_two(b);
			sort_five(a, b);
		}
	}
	return (0);
}