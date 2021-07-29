/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasbss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:31 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/29 15:35:51 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a)
{
	t_list	*first;
	t_list	*next;

	first = ft_lstfirst(a);
	next = first->next;
	if (ft_lstsize(a) < 2)
		return ;
	first->previous = next;
	first->next = next->next;
	next->next = first;
	next->previous = NULL;
	return ;
}

void	sb(t_list *b)
{
	t_list	*first;
	t_list	*next;

	first = ft_lstfirst(b);
	next = first->next;
	if (ft_lstsize(b) < 2)
		return ;
	first->previous = next;
	first->next = next->next;
	next->next = first;
	next->previous = NULL;
	return ;
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	return ;
}
