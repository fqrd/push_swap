/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:37:20 by fcaquard          #+#    #+#             */
/*   Updated: 2021/12/30 13:03:26 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"

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
	int					index;
	int					position;
	int					nra;
	int					nrra;
	int					destination;
	int					nrb;
	int					nrrb;
	struct s_candidate	*next;
	struct s_candidate	*previous;
}				t_candidate;

int			parser(int argc, char *argv[], t_stack **a);
int			duplicates_check(t_stack *lst);
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
t_stack		*lst_new(t_stack **previous, int content);
size_t		lst_size(t_stack *lst);
int			lst_issorted(t_stack *lst, int descending);
void		lst_delete(t_stack **lst);
int			lst_clear(t_stack **lst, int val);
t_stack		*lst_rewind(t_stack *lst);
t_stack		*lst_forward(t_stack *lst);
t_context	*init_context(void);
void		context_reset(t_stack **a, t_stack **b, t_context **context);
int			navigate(t_stack **a, t_stack **b, t_candidate **c);
int			get_position(t_stack **b, int index);
int			sort_three(t_stack **a);
int			sort_four(t_stack **a, t_stack **b);
int			sort_five(t_stack **a, t_stack **b);
int			sort_big(t_stack **a, t_stack **b);
void		find_destination(t_stack **b, t_candidate **c, t_context **context);
t_candidate	*find_candidates(t_stack **a, t_context **context, t_candidate *c);
t_candidate	*candidate_rewind(t_candidate *lst);
int			clear_candidates(t_candidate **lst, int value);
t_route		*route_rewind(t_route *lst);
t_route		*map_routes(t_candidate **c, t_route *route, int i, int j);
void		clear_routes(t_route **route);
#endif
