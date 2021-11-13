/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:21 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 13:46:09 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duplicates_check(t_list *lst)
{
	t_list *p;

	while (lst->next)
	{
		p = lst;
		while (p->next)
		{	
			p = p->next;
			if (p->content == lst->content)
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

// int	lst_lowest(t_list *lst)
// {
// 	int lowest;
//
// 	lowest = NULL;
// 	while (lst->next)
// 	{
// 		if (lst->content < lowest)
// 			lowest = lst->content;
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// int	lst_highest(t_list *lst)
// {
// 	int highest;
//
// 	highest = NULL;
// 	while (lst->next)
// 	{
// 		if (lst->content > highest)
// 			highest = lst->content;
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

t_list	*expected_order(t_list *lst)
{
	
	return (lst);
}

void	*check(t_list *lst)
{
	// int highest;
	// int lowest;

	if (!duplicates_check(lst_rewind(lst)))
		return (NULL);
	else
	{
		printf("All good: No duplicates\n");
	}
	// lowest = lst_lowest(lst_rewind(lst));
	// highest = lst_highest(lst_rewind(lst));
	// lst = expected_order(lst_rewind(lst));
}