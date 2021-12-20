/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:09:36 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 20:02:05 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_route	*route_rewind(t_route *lst)
{
	while (lst)
	{
		if (!lst->previous)
			return (lst);
		lst = lst->previous;
	}
	return (lst);
}

t_candidate	*candidate_rewind(t_candidate *lst)
{
	while (lst)
	{
		if (!lst->previous)
			return (lst);
		lst = lst->previous;
	}
	return (lst);
}

t_link	*lst_rewind(t_link *lst)
{
	while (lst)
	{
		if (!lst->previous)
			return (lst);
		lst = lst->previous;
	}
	return (lst);
}

t_link	*lst_forward(t_link *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
