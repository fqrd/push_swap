/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:50:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:08:44 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_indexes(t_link **lst, int len)
{
	int		gap;
	t_link	*p;

	*lst = lst_rewind(*lst);
	while ((*lst))
	{
		gap = 0;
		p = lst_rewind(*lst);
		while (p)
		{
			if ((((t_stack *)(p->content))->content) > ((t_stack *)(*lst)->content)->content)
				gap++;
			if (!p->next)
				break ;
			p = p->next;
		}
		((t_stack *)(*lst)->content)->index = len - gap;
		if (!(*lst)->next)
			break ;
		*lst = (*lst)->next;
	}
	*lst = lst_rewind(*lst);
}
