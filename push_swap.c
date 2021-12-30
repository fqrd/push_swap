/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/30 13:06:20 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	ft_puterror(char *err)
{
	write(STDERR_FILENO, err, ft_strlen(err));
}

static void	set_indexes(t_stack **lst, int len)
{
	int		gap;
	t_stack	*p;

	*lst = lst_rewind(*lst);
	while ((*lst))
	{
		gap = 0;
		p = lst_rewind(*lst);
		while (p)
		{
			if (p->content > (*lst)->content)
				gap++;
			if (!p->next)
				break ;
			p = p->next;
		}
		(*lst)->index = len - gap;
		if (!(*lst)->next)
			break ;
		*lst = (*lst)->next;
	}
	*lst = lst_rewind(*lst);
}

static int	sort(size_t size, t_stack **a, t_stack **b)
{
	if (size <= 3)
		sort_three(a);
	else if (size <= 4)
		sort_four(a, b);
	else if (size <= 5)
		sort_five(a, b);
	else
		return (sort_big(a, b));
	return (1);
}

static int	push_swap(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!parser(argc, argv, &a))
		return (0);
	if (!duplicates_check(a))
		return (lst_clear(&a, 0));
	set_indexes(&a, lst_size(a));
	if (lst_issorted(a, 0))
		return (lst_clear(&a, 1));
	if (!sort(lst_size(a), &a, &b))
		return (lst_clear(&a, 1) && lst_clear(&b, 0));
	return (lst_clear(&a, 1) && lst_clear(&b, 1));
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (!push_swap(argc, argv))
		ft_puterror("Error\n");
	return (0);
}
