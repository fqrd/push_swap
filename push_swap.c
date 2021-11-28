/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/28 15:29:39 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_action(char *str)
{
	printf("%s\n", str);
}

int	init_checks(int argc, char *argv[], t_stack **a)
{
	if (argc < 2)
		return (0);
	if (!valid_number(argc, argv))
		return (0);
	*a = lst_create(argc, argv);
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
	display_stacks(a, b);
	return (lst_clear(&a, 1) && lst_clear(&b, 1));
}

int	main(int argc, char *argv[])
{
	if (!exec(argc, argv))
		printf("Error\n");
	return (0);
}
