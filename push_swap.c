/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/13 18:35:32 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_swap(t_list **x, t_list **y)
{
	display_stacks(*x, *y);
	sa(x);
	// display_stacks(*x, *y);
	pa(x, y);
	// display_stacks(*x, *y);
	pa(x, y);
	// display_stacks(*x, *y);
	pa(x, y);
	// display_stacks(*x, *y);
	pa(x, y);
	// display_stacks(*x, *y);
	pa(x, y);
	// display_stacks(*x, *y);
	rr(x, y);
	// display_stacks(*x, *y);
	rrr(x, y);
	// display_stacks(*x, *y);
	ss(x, y);
	// display_stacks(*x, *y);
}

void	display_stacks(t_list *a, t_list *b)
{
	printf("***A STACK ***\n");
	if (a)
	{
		a = ft_lsttop(a);
		while (a->previous)
		{
			printf("%d\n", a->content);
			a = a->previous;
		}
		printf("%d\n", a->content);
	}
	printf("***B STACK ***\n");
	if (b)
	{
		b = ft_lsttop(b);
		while (b->previous)
		{
			printf("%d\n", b->content);
			b = b->previous;
		}
		printf("%d\n", b->content);
	}
	printf("\n----------------\n\n");
}

int	main(int argc, char *argv[])
{
	int		i;
	int		*na;
	int		*nb;
	t_list	*a;
	t_list	*b;

	if (argc < 2)
	{
		printf("ERROR: No arguments.\n");
		return (0);
	}

	if (!check_inputs(argc, argv))
	{
		printf("ERROR: inputs checked.\n");
		return (0);
	}

	a = create_list(argc, argv);
	if (!duplicates_check(lst_rewind(a)))
	{
		printf("ERROR: duplicates\n");
		return (0);
	}

	b = NULL;
	push_swap(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
