/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:34:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/16 11:37:24 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
