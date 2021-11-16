/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/16 11:46:00 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_action(char *str)
{
	/* TO DO */
	printf("%s\n", str);
}

int	main(int argc, char *argv[])
{
	int		*na;
	int		*nb;
	t_list	*a;
	t_list	*b;

	if (argc < 2)
	{
		printf("Error\n");
		printf("ERROR: No arguments.\n");
		return (0);
	}

	if (!valid_number(argc, argv))
	{
		printf("Error\n");
		printf("ERROR: inputs checked.\n");
		return (0);
	}

	a = lst_create(argc, argv);

	if (!duplicates_check(lst_rewind(a)))
	{
		lst_clear(&a);
		printf("Error\n");
		printf("ERROR: duplicates\n");
		return (0);
	}

	set_indexes(&a, lst_size(a));

	// display_stacks(a, b);

	a = lst_rewind(a);
	// printf("first: %d / index: %d / len: %d\n", a->content, a->index, argc - 1);
	b = NULL;

	// display_stacks(a, a);

	if (lst_issorted(a))
	{
		lst_clear(&a);
		printf("already sorted \n");
		return (0);
	}

	if (argc - 1 == 2)
		sort_two(&a);
	else if (argc - 1 == 3)
		sort_three(&a);
	else if (argc - 1 == 5)
		sort_five(&a, &b);
	else
		display_stacks(a, b);

	display_stacks(a, b);
	
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
