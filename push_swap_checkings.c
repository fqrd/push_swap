/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:21 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/12 18:51:37 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reccursive_duplicates_check(t_list *lst)
{
	int i;
	t_list *p;

	i = 0;
	p = lst;
	while (lst->next)
	{
		lst = lst->next;
		if (lst->content == p->content)
			return (0);
	}
	if (p->next && p->next->next)
		return (reccursive_duplicates_check(p->next));
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

	if (!reccursive_duplicates_check(lst_rewind(lst)))
		return (NULL);
	else
	{
		printf("All good: No duplicates\n");
	}
	// lowest = lst_lowest(lst_rewind(lst));
	// highest = lst_highest(lst_rewind(lst));
	// lst = expected_order(lst_rewind(lst));
}