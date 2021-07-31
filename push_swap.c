/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/31 15:23:04 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*test(int *p)
{
	p[9] = INT_MAX;
	p[8] = INT_MIN;
	p[7] = 8;
	p[6] = 7;
	p[5] = 6;
	p[4] = 5;
	p[3] = 4;
	p[2] = 3;
	p[1] = 2;
	p[0] = 1;
	return (p);
}

void	push_swap(t_list **x, t_list **y)
{
	display_stacks(*x, *y);
	sa(x);
	display_stacks(*x, *y);
	pa(x, y);
	display_stacks(*x, *y);
	pa(x, y);
	display_stacks(*x, *y);
	pa(x, y);
	display_stacks(*x, *y);
	pa(x, y);
	display_stacks(*x, *y);
	pa(x, y);
	display_stacks(*x, *y);
	rr(x, y);
	display_stacks(*x, *y);
	rrr(x, y);
	display_stacks(*x, *y);
	ss(x, y);
	display_stacks(*x, *y);
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

int	main(void)
{
	int		*na;
	int		*nb;
	int		i;
	t_list	*a;
	t_list	*b;

	i = 0;
	na = malloc(sizeof(int) * 10);
	if (!na)
		return (0);
	na = test(na);
	a = create_list(na, 10);
	b = NULL;
	push_swap(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	free(na);
	return (0);
}
