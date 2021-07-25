/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/25 19:23:35 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*test_all_negative(int *p)
{
	p[0] = -5;
	p[1] = -4;
	p[2] = -6;
	p[3] = -3;
	p[4] = -2;
	p[5] = -9;
	p[6] = -4;
	p[7] = -100;
	p[8] = -7;
	p[9] = INT_MIN;
	return (p);	
}

static int	*test_duplicates(int *p)
{
	p[0] = -2;
	p[1] = -5;
	p[2] = -4;
	p[3] = -6;
	p[4] = -2;
	p[5] = -9;
	p[6] = -9;
	p[7] = -100;
	p[8] = -7;
	p[9] = INT_MIN;
	return (p);	
}

static int	*test_all_positive(int *p)
{
	p[0] = 45;
	p[1] = 5;
	p[2] = 4;
	p[3] = 6;
	p[4] = 2;
	p[5] = 29;
	p[6] = 96;
	p[7] = 1001;
	p[8] = 700;
	p[9] = INT_MIN;
	return (p);	
}

t_list *create_list(int *p)
{
	int i;
	t_list *next;
	t_list *previous;

	i = 0;
	next = NULL;
	previous = NULL;
	while (p[i] != INT_MIN)
	{
		next = ft_lstnew(previous, &p[i]);
		if (previous)
			previous->next = next;
		previous = next;
		i++;
	}
	return (next);
}

int	main(void)
{
	int *na;
	int *nb;
	int i;
	t_list *a;
	t_list *b;

	i = 0;
	na = malloc(sizeof(int) * 10);
	if (!na)
		return (0);
	// a = test_all_negative(a);
	// a = test_duplicates(a);
	na = test_all_positive(na);
	
	a = create_list(na);	
	b = NULL;


	// while (na[i] != INT_MIN)
	// {
	// 	printf("%d\n", na[i]);
	// 	i++;
	// }

	a = ft_lstfirst(a);

	while (a->next)
	{
		printf("%d\n", *((int *) a->content));
		a = a->next;
	}

	free(na);
	// ft_lstclear(&a, &empty_list);
	return (0);
}
