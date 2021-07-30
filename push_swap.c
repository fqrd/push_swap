/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/30 16:20:09 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*test(int *p)
{
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	p[5] = 6;
	p[6] = 7;
	p[7] = 8;
	p[8] = INT_MIN;
	return (p);
}

void	push_swap(t_list **x, t_list **y)
{
	ra(x);
	ra(x);
}

void	display_stacks(t_list *a, t_list *b)
{
	printf("***A STACK ***\n");
	if (a)
	{
		a = ft_lstfirst(a);
		while (a->next)
		{
			printf("%d\n", a->content);
			a = a->next;
		}
		printf("%d\n", a->content);
	}
	printf("***B STACK ***\n");
	if (b)
	{
		b = ft_lstfirst(b);
		while (b->next)
		{
			printf("%d\n", b->content);
			b = b->next;
		}
		printf("%d\n", b->content);
	}
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
	a = create_list(na);
	b = NULL;
	push_swap(&a, &b);
	display_stacks(a, b);
	free(na);
	return (0);
}
