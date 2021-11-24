/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:21 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/24 11:51:31 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_isinteger(char *str, int negative)
{
	long long nbr;
	int	i;

	nbr = 0;
	i = negative;
	while (str[i])
	{
		nbr = 10 * nbr + (str[i] - '0');
		if ((negative == 0 && nbr > INT_MAX) || (negative == 1 && nbr * (-1) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	valid_number(int argc, char *argv[])
{
	int i;
	int j;
	int negative;

	i = 1;
	while (i < argc)
	{
		negative = 0;
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 &&  argv[i][j] == '-')
				negative = 1;
			else
			{
				if(!ft_isdigit(argv[i][j]))
					return (0);
			}
		}
		if(!ft_isinteger(argv[i], negative))
			return (0);
		i++;
	}
	return (1);
}

int	duplicates_check(t_stack *lst)
{
	t_stack *p;
	while (lst->next)
	{
		// printf("dup check: %d \n", lst->content);
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
