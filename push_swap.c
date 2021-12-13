/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/13 13:55:45 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_action(char *str, int is_a_stack)
{
	(void) is_a_stack;
	// char *c1;
	// char *c2;

	// c1 = "\x1B[0m";
	// c2 = "\x1B[0m";
	// if (is_a_stack)
	// 	c1 = "\x1B[34m";
	// printf("%s %s %s\n", c1, str, c2);
	ft_printf("%s\n", str);
}

static int	free_splits(char **splits)
{
	int i;

	i = 0;
	while (splits[i])
		free (splits[i++]);
	free(splits);
	return (0);
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

static int	the_ultimate_parse(int argc, char *argv[], t_stack **a)
{
	int arg;
	int i;
	char **splits;

	arg = 1;
	while (arg < argc)
	{
		splits = ft_split(argv[arg], ' ');
		i = 0;
		while (splits[i])
		{
			if (!valid_number(splits[i]))
				return (free_splits(splits));
			else
				*a = lst_new(a, ft_atoi(splits[i]));
			i++;
		}
		free_splits(splits);
		arg++;
	}
	return (1);
}

int	init_checks(int argc, char *argv[], t_stack **a)
{
	if (argc < 2)
		return (0);
	if (!the_ultimate_parse(argc, argv, a))
		return (lst_clear(a, 0));
	if (!duplicates_check(*a))
		return (lst_clear(a, 0));
	return (1);
}

void	push_swap(size_t argc, t_stack **a, t_stack **b)
{
	if (argc <= 3)
		sort_three(a);
	else if (argc == 5)
		sort_five(a, b);
	else
	{
		sort_above_entry(a, b);
	}
}

int	exec(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!init_checks(argc, argv, &a))
		return (0);
	set_indexes(&a, lst_size(a));
	if (lst_issorted(a, 0))
		return (lst_clear(&a, 1));
	push_swap((size_t) argc - 1, &a, &b);
	// display_stacks(a, b);
	return (lst_clear(&a, 1) && lst_clear(&b, 1));
}

int	main(int argc, char *argv[])
{
	if (!exec(argc, argv))
		printf("Error\n");
	return (0);
}
