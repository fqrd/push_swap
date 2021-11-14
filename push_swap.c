/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/14 14:42:36 by fcaquard         ###   ########.fr       */
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

	a = create_list(argc, argv);
	if (!duplicates_check(lst_rewind(a)))
	{
		ft_lstclear(&a);
		printf("Error\n");
		printf("ERROR: duplicates\n");
		return (0);
	}

	pre_sort(lst_rewind(a), argc - 1);

	// if (argc - 1 == 1)
	// {
	// 	return (0);
	// }
	// else if (argc - 1 <= 3)
	// {
		
	// }
	// else if (argc - 1 < 10)
	// {
		
	// }
	// else if (argc - 1 < 100)
	// {
		
	// }
	// else if (argc - 1 < 500)
	// {
		
	// }
	// else if (argc - 1 < 1000)
	// {
		
	// }
	// else
	// {

	// }


	b = NULL;
	push_swap(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
