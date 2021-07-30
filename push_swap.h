/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/07/30 15:23:59 by fcaquard         ###   ########.fr       */
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
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

t_list	*ft_lstnew(t_list *previous, int content);
t_list	*ft_lstfirst(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del) (void *));
void	empty_list(t_list *list);
size_t	ft_lstsize(t_list *lst);

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

#endif