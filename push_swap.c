/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/29 15:32:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*test_all_negative(int *p)
{
	int *p[10] = {
		-2, -5, -9, -4, -1, -6, -7, -8, -10, INT_MIN
	};
	return (p);	
}

static int	*test_duplicates(int *p)
{
	int *p[10] = {
		-2, 5, -9, -4, -1, 6, -7, -8, -1, INT_MIN
	};
	return (p);	
	return (p);	
}

static int	*test_all_positive(int *p)
{
	int *p[10] = {
		2, 5, 9, 4, 1, 6, 7, 8, 15, INT_MIN
	};
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
