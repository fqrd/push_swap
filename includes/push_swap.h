/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/24 11:51:43 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

// list manipulations functions
t_stack	*lst_new(t_stack **previous, int content);
t_stack	*lst_forward(t_stack *lst);
void	lst_delete(t_stack **lst);
int		lst_clear(t_stack **lst, int val);
size_t	lst_size(t_stack *lst);
t_stack	*lst_create(int argc, char *argv[]);
t_stack	*lst_rewind(t_stack *lst);

// checks & prepare 
int		duplicates_check(t_stack *lst);
int		valid_number(int argc, char *argv[]);
// void	pre_sort(t_stack *lst, int len);
int		lst_issorted(t_stack *lst);
void	set_indexes(t_stack **lst, int len);

// sorting functions common core
void	switchy(t_stack **x);
void	pushy(t_stack **x, t_stack **y);
void	returny(t_stack **x);
void	rreturny(t_stack **x);

// sorting functions
t_stack	**sa(t_stack **a);
t_stack	**sb(t_stack **b);
t_stack	**ss(t_stack **a, t_stack **b, int pass_b);
t_stack	**pa(t_stack **a, t_stack **b, int pass_b);
t_stack	**pb(t_stack **a, t_stack **b, int pass_b);
t_stack	**ra(t_stack **a);
t_stack	**rb(t_stack **b);
t_stack	**rr(t_stack **a, t_stack **b, int pass_b);
t_stack	**rra(t_stack **a);
t_stack	**rrb(t_stack **b);
t_stack	**rrr(t_stack **a, t_stack **b, int pass_b);

// libft
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);

// sort
int		sort_two(t_stack **a);
int		sort_three(t_stack **a);
int		sort_five(t_stack **a, t_stack **b);

// debug
void	display_stacks(t_stack *a, t_stack *b);
void	print_action(char *str);

#endif
