/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:21 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 18:31:15 by fcaquard         ###   ########.fr       */
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

int	check_inputs(int argc, char *argv[])
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

int	duplicates_check(t_list *lst)
{
	t_list *p;
	while (lst->next)
	{
		printf("dup check: %d \n", lst->content);
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
