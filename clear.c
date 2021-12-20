/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:11:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 17:58:00 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	clear_candidates(t_candidate **lst, int value)
{
	t_candidate	*p;

	*lst = candidate_rewind(*lst);
	while (*lst)
	{
		if (!(*lst)->next)
		{
			free(*lst);
			break ;
		}
		p = (*lst)->next;
		free (*lst);
		*lst = p;
	}
	return (value);
}

void	clear_routes(t_route **route)
{
	t_route	*p;

	*route = route_rewind(*route);
	while (*route)
	{
		if (!(*route)->next)
		{
			free(*route);
			break ;
		}
		p = (*route)->next;
		free (*route);
		*route = p;
	}
}
