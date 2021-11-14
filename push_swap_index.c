/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:50:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/14 14:55:27 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	get_extremes(t_list *lst, int flag)
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
}

static void	set_indexes(t_list **lst, int len)
{
	int gap;
	t_list *p;

	printf("len: %d\n", len);

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
		printf("number: %d / index: %d\n", (*lst)->content, len - gap);
		if (!(*lst)->next)
			break;
		*lst = (*lst)->next;
	}
}

void	pre_sort(t_list *lst, int len)
{
	// int	highest;
	// int lowest;

	// highest = get_extremes(lst_rewind(lst), 1);
	// lowest = get_extremes(lst_rewind(lst), 0);
	// printf("lowest: %d / highest: %d\n", lowest, highest);

	set_indexes(&lst, len);
}