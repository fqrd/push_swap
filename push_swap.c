/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/20 19:26:20 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_action(char *str)
{
	/* TO DO */
	printf("%s\n", str);
}

int	init_checks(int argc, char *argv[], t_list **a)
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

void	push_swap(int argc, t_list **a, t_list **b)
{
	if (argc - 1 <= 3)
		sort_three(a);
	else if (argc - 1 == 5)
		sort_five(a, b);
	else
		display_stacks(*a, *b);
}

int	exec(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!init_checks(argc, argv, &a))
		return (0);
	set_indexes(&a, lst_size(a));
	if (lst_issorted(a))
		return (lst_clear(&a, 1));
	push_swap(argc, &a, &b);
	
	/* debug */
	display_stacks(a, b);
	
	return (lst_clear(&a, 1) && lst_clear(&b, 1));
}

int	main(int argc, char *argv[])
{
	if (!exec(argc, argv))
		printf("Error\n");
	return (0);
}
