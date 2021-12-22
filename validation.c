/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:21:21 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/22 19:29:30 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ft_isinteger(char *str, int negative)
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

static int	valid_number(char *str)
{
	int	i;
	int	negative;

	negative = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			negative = 1;
		else
		{
			if (!ft_isdigit(str[i]))
				return (0);
		}
		i++;
	}
	if (!ft_isinteger(str, negative))
		return (0);
	return (1);
}

static int	free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
		free (splits[i++]);
	free(splits);
	return (0);
}

int	parser(int argc, char *argv[], t_stack **a)
{
	int		arg;
	int		i;
	char	**splits;

	arg = 1;
	while (arg < argc)
	{
		splits = ft_split(argv[arg], ' ');
		i = 0;
		while (splits[i])
		{
			if (!valid_number(splits[i]))
				return (lst_clear(a, 1) && free_splits(splits));
			else
			{
				*a = lst_new(a, ft_atoi(splits[i]));
				if (!(*a))
					return (0);
			}
			i++;
		}
		free_splits(splits);
		arg++;
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
