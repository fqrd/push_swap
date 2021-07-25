/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:08 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/25 17:37:10 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list *get_first(s_list *current)
{
	s_list *tmp;

	tmp = current;
	while (current->previous)
		current = current->previous;
	return (current);
}

s_list *get_last(s_list *current)
{
	s_list *tmp;

	tmp = current;
	while (current->next)
		current = current->next;
	return (current);
}

void push_top(s_list *new, s_list *current)
{
	s_list *tmp;
	s_list *first;

	first = get_first(current);
	new->previous = NULL;
	new->next = first;
}

void swap(s_list *a, s_list *b)
{
	s_list *tmp;
	tmp = a;
	a = b;
	b = tmp;
	return (a);
}