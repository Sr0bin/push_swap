/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:07:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/29 14:52:30 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "struct.h"
//------------------------------------------------- 
//					Target
//------------------------------------------------- 
t_node	*find_target_inside(t_stack *stack, t_node *node);
t_node	*find_target_new_hl(t_stack *stack, t_node *node);
t_node	*find_target_final(t_stack *stack, t_node *node);
void	find_target(t_context context, t_node *node);
void	find_best_moves(t_context context, t_node *node);
//------------------------------------------------- 
//					Node
//------------------------------------------------- 
int		depth_node(t_stack stack, t_node *node);
t_node	*find_node(t_stack *stack, int value);
t_list	*node_n(t_list *node, size_t n);
//------------------------------------------------- 
//					Stack
//------------------------------------------------- 
int		is_stack_sorted(t_stack *stack);
t_node	*is_stack_insertable(t_stack *receiver, t_stack *inserted);
//------------------------------------------------- 
//					Movelist
//------------------------------------------------- 
t_list	*mvlist_replace_n(t_list **movelist, t_move move, size_t n, size_t end);
void	optimize_movelist(t_list **movelist);
void	shortest_rotate(t_context c, t_stack *s, t_node *n, t_list **mvlst);
void	apply_apnd_mvlist(t_context *context, t_list **movelist);
void	replace_ra_rb(t_list **start);
void	replace_rra_rrb(t_list **start);
void	movelist_add_sa_ra(t_list **movelist);
//------------------------------------------------- 
//					Algo
//------------------------------------------------- 
void	apply_best_moves(t_context *context);
void	sort_three(t_context *context);
void	dumb_sort(t_context *context);
void	stack_a_loop(t_context *context);
void	update_stack_target(t_context *context);
#endif
