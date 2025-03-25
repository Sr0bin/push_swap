/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:07:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/25 18:09:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "struct.h"
int	depth_node(t_stack stack, t_node *node);
int	is_stack_sorted(t_stack *stack);
t_node	*find_target_inside(t_context context, t_node *node);
t_node	*find_target_new_HL(t_context context, t_node *node);
void	find_target(t_context context, t_node *node);
void	update_stack_target(t_context *context);
void	clean_stack(t_stack *stack);
void	apply_best_moves(t_context *context);
void	stack_a_loop(t_context *context);
int	is_stack_insertable(t_stack *receiver, t_stack *inserted);
#endif
