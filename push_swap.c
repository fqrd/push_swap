/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 15:34:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_swap(t_list **x, t_list **y)
{
	// display_stacks(*x, *y);
	// sa(x);
	// display_stacks(*x, *y);
	// rra(x);
	// display_stacks(*x, *y);
	// ra(x);
	// display_stacks(*x, *y);
	// sa(x);
	// display_stacks(*x, *y);
	// sa(x);
	// display_stacks(*x, *y);
	// pa(x, y);
	// display_stacks(*x, *y);
	// pa(x, y);
	// display_stacks(*x, *y);
	// pa(x, y);
	// display_stacks(*x, *y);
	// pa(x, y);
	// display_stacks(*x, *y);
	// pa(x, y);
	// display_stacks(*x, *y);
	// rr(x, y);
	// display_stacks(*x, *y);
	// rrr(x, y);
	// display_stacks(*x, *y);
	// ss(x, y);
	// display_stacks(*x, *y);
}

void	display_stacks(t_list *a, t_list *b)
{
	printf("***A STACK ***\n");
	if (a)
	{
		a = lst_rewind(a);
		while (a)
		{
			printf("%d > %d\n", a->index, a->content);
			if (!a->next)
				break;
			a = a->next;
		}
	}
	printf("***B STACK ***\n");
	if (b)
	{
		b = lst_rewind(b);
		while (b)
		{
			printf("%d > %d\n", b->index, b->content);
			if(!b->next)
				break;
			b = b->next;
		}
	}
	printf("\n----------------\n\n");
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

	if (!check_inputs(argc, argv))
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

	pre_sort(lst_rewind(a), argc - 1);

	// display_stacks(a, b);

	a = lst_rewind(a);
	// printf("first: %d / index: %d / len: %d\n", a->content, a->index, argc - 1);
	b = NULL;

	// display_stacks(a, a);

	if (lst_issorted(a))
	{
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
		push_swap(&a, &b);

	display_stacks(a, b);
	
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
