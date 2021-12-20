/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:09:36 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 13:43:59 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_route	*route_rewind(t_route *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->previous)
				return (lst);
			lst = lst->previous;
		}
	}
	return (lst);
}

t_candidate	*candidate_rewind(t_candidate *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->previous)
				return (lst);
			lst = lst->previous;
		}
	}
	return (lst);
}

t_stack	*lst_rewind(t_stack *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->previous)
				return (lst);
			lst = lst->previous;
		}
	}
	return (lst);
}

t_stack	*lst_forward(t_stack *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->next)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}
