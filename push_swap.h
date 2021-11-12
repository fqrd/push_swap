/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/12 18:03:31 by fcaquard         ###   ########.fr       */
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

t_list	*ft_lstnew(t_list **previous, int content);
t_list	*ft_lstbottom(t_list *lst);
t_list	*ft_lsttop(t_list *lst);
void	ft_lstdelone(t_list **lst);
void	ft_lstclear(t_list **lst);
size_t	ft_lstsize(t_list *lst);
t_list	*create_list(int *p, size_t len);
t_list	*lst_rewind(t_list *lst);
void	*check(t_list *lst);

void	switchy(t_list **x);
void	pushy(t_list **x, t_list **y);
void	returny(t_list **x);
void	rreturny(t_list **x);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	display_stacks(t_list *a, t_list *b);

#endif