/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/15 15:34:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

// list manipulations functions
t_list	*lst_new(t_list **previous, int content);
t_list	*lst_forward(t_list *lst);
void	lst_delete(t_list **lst);
void	lst_clear(t_list **lst);
size_t	lst_size(t_list *lst);
t_list	*lst_create(int argc, char *argv[]);
t_list	*lst_rewind(t_list *lst);

// checks & prepare 
int		duplicates_check(t_list *lst);
int		check_inputs(int argc, char *argv[]);
void	pre_sort(t_list *lst, int len);
int		lst_issorted(t_list *lst);

// sorting functions common core
void	switchy(t_list **x);
void	pushy(t_list **x, t_list **y);
void	returny(t_list **x);
void	rreturny(t_list **x);

// sorting functions
t_list	**sa(t_list **a);
t_list	**sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
t_list	**ra(t_list **a);
t_list	**rb(t_list **b);
void	rr(t_list **a, t_list **b);
t_list	**rra(t_list **a);
t_list	**rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// libft
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);

// sort
int		sort_two(t_list **a);
int		sort_three(t_list **a);
int		sort_five(t_list **a, t_list **b);

// debug
void	display_stacks(t_list *a, t_list *b);
#endif
