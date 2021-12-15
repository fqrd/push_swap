/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/15 19:12:36 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_action(char *str)
{
	ft_printf("%s\n", str);
}

void	sort(size_t argc, t_stack **a, t_stack **b)
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

static int	push_swap(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	if (argc < 2)
		return (0);
	if (!parser(argc, argv, &a))
		return (lst_clear(&a, 0));
	if (!duplicates_check(a))
		return (lst_clear(&a, 0));
	set_indexes(&a, lst_size(a));
	if (lst_issorted(a, 0))
		return (lst_clear(&a, 1));
	sort((size_t) argc - 1, &a, &b);
	display_stacks(a, b);
	return (lst_clear(&a, 1));
	// return (lst_clear(&a, 1) && lst_clear(&b, 1));
}

int	main(int argc, char *argv[])
{
	if (!push_swap(argc, argv))
		printf("Error\n");
	return (0);
}
