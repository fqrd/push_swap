/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:21 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/13 11:23:07 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_isinteger(char *str, int negative)
{
	long long	nbr;
	int			i;

	nbr = 0;
	i = negative;
	while (str[i])
	{
		nbr = 10 * nbr + (str[i] - '0');
		if ((negative == 0 && nbr > INT_MAX)
			|| (negative == 1 && nbr * (-1) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	duplicates_check(t_stack *lst)
{
	t_stack	*p;
	lst = lst_rewind(lst);

	while (lst && lst->next)
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
