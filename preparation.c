/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:50:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/20 19:08:32 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// unused for now
/*static int	get_extremes(t_list *lst, int flag)
{
	int nbr;
	
	nbr = lst->content;
	while (lst)
	{
		if (flag == 0 && lst->content < nbr)
			nbr = lst->content;
		if (flag == 1 && lst->content > nbr)
			nbr = lst->content;
		if (!lst->next)
			break;
		lst = lst->next;
	}
	return (nbr);
}*/

void	set_indexes(t_list **lst, int len)
{
	int gap;
	t_list *p;

	// printf("len: %d\n", len);

	*lst = lst_rewind(*lst);
	while ((*lst))
	{
		gap = 0;
		p = lst_rewind(*lst);
		while (p)
		{
			if (p->content > (*lst)->content)
				gap++;
			if (!p->next)
				break;
			p = p->next;
		}
		(*lst)->index = len - gap;
		// printf("number: %d / index: %d\n", (*lst)->content, (*lst)->index);
		if (!(*lst)->next)
			break;
		*lst = (*lst)->next;
	}
	*lst = lst_rewind(*lst);
}

/*void	pre_sort(t_list *lst, int len)
{
	// usused start
		// int	highest;
		// int lowest;

		// highest = get_extremes(lst_rewind(lst), 1);
		// lowest = get_extremes(lst_rewind(lst), 0);
		// printf("lowest: %d / highest: %d\n", lowest, highest);
	// unused end
}*/
