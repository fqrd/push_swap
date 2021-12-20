/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:15 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 21:34:04 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_puterror(char *err)
{
	return (write(2, err, ft_strlen(err)));
}

static int	sort(size_t argc, t_stack **a, t_stack **b)
{
	if (argc <= 3)
		sort_small(a);
	else if (argc == 5)
		sort_medium(a, b);
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
	if (argc < 2)
		return (0);
	if (!parser(argc, argv, &a))
		return (lst_clear(&a, 0));
	if (!duplicates_check(a))
		return (lst_clear(&a, 0));
	set_indexes(&a, lst_size(a));
	if (lst_issorted(a, 0))
		return (lst_clear(&a, 1));
	if (!sort((size_t) argc - 1, &a, &b))
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
