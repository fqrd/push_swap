/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/20 12:08:22 by fcaquard         ###   ########.fr       */
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

typedef struct s_context
{
	size_t			limitb;
	size_t			sizea;
	size_t			sizeb;
	int				highestb;
	int				lowestb;
	int				group_size;
	int				group_inc;
	int				pushed_inc;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
}				t_context;

typedef struct s_route
{
	int				operations;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	struct s_route	*next;
	struct s_route	*previous;
}				t_route;

typedef struct s_candidate
{
	int	index;
	int	position;
	int	nra;
	int	nrra;
	int	destination;
	int	nrb;
	int	nrrb;
	struct s_candidate	*next;
	struct s_candidate	*previous;
}				t_candidate;

int			lst_clear(t_stack **lst, int val);
void		lst_delete(t_stack **lst);
size_t		lst_size(t_stack *lst);
t_stack		*lst_create(int argc, char *argv[]);
t_stack		*lst_forward(t_stack *lst);
t_stack		*lst_new(t_stack **previous, int content);
t_stack		*lst_rewind(t_stack *lst);
int			duplicates_check(t_stack *lst);
int			parser(int argc, char *argv[], t_stack **a);
void		set_indexes(t_stack **lst, int len);
void		pushy(t_stack **x, t_stack **y);
void		returny(t_stack **x);
void		rreturny(t_stack **x);
void		switchy(t_stack **x);
t_stack		**pa(t_stack **a, t_stack **b, int pass_b);
t_stack		**pb(t_stack **a, t_stack **b, int pass_b);
t_stack		**ra(t_stack **a);
t_stack		**rb(t_stack **b);
t_stack		**rr(t_stack **a, t_stack **b, int pass_b);
t_stack		**rra(t_stack **a);
t_stack		**rrb(t_stack **b);
t_stack		**rrr(t_stack **a, t_stack **b, int pass_b);
t_stack		**sa(t_stack **a);
t_stack		**sb(t_stack **b);
t_stack		**ss(t_stack **a, t_stack **b, int pass_b);

// void		candidate_reset(t_candidate **candidate);
int			get_position(t_stack **b, int index);
void	find_destination(t_stack **b, t_candidate **c, t_context **context);
int			find_and_apply_route(t_stack **a, t_stack **b, t_candidate **c);
t_context	*init_context(void);
void		context_reset(t_stack **a, t_stack **b, t_context **context);
int			sort_three(t_stack **a);
int			sort_five(t_stack **a, t_stack **b);
int			sort_above_entry(t_stack **a, t_stack **b);
int			lst_issorted(t_stack *lst, int descending);
void		display_stacks(t_stack *a, t_stack *b);
void		print_action(char *str);



t_candidate	*find_candidates(t_stack **a, t_context **context, t_candidate *c);
// int			init_candidate(t_candidate **previous);



void	debug_candidates(t_candidate **c);
void	debug_routes(t_route **route);
void	display_stacks(t_stack *a, t_stack *b);

t_candidate *candidate_rewind(t_candidate *lst);
t_route	*route_rewind(t_route *lst);


// display
int	ft_puterror(char *err);



// CLEAR
int	clear_candidates(t_candidate **lst, int value);
int	clear_routes(t_route **route, int value);

#endif
