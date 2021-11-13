/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:21 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 14:26:34 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
// should check directly when creating the list from argv
static int	numeric_check(t_list *lst)
{
	int i;
	
	while (lst->next)
	{
		i = 0;
		while (lst->str[i] != '\0')
		{
			if (!ft_isdigit(lst->str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}
// should check directly when creating the list from argv
static int	integer_check_convert(t_list *lst)
{
	while (lst->next)
	{
		if(lst->content > INT_MAX || lst->content < INT_MIN)
			return (0);
		else
			lst->content = (int) lst->content;
	}
	return (1);
}
*/
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

int	check(t_list *lst)
{
	/*
	if (!numeric_check(lst_rewind(lst)))
		return (0);
	if (!integer_check_convert(lst_rewind(lst)))
		return (0);
	*/
	if (!duplicates_check(lst_rewind(lst)))
		return (0);
	return (1);
}