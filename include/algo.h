/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:07:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/24 15:38:03 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "struct.h"
int	depth_node(t_stack stack, t_node *node);
int	is_stack_sorted(t_stack *stack);
void	find_target(t_context context, t_node *node);
void	update_stack_target(t_context *context);
void	clean_stack(t_stack *stack);
void	apply_best_moves(t_context *context);
void	stack_a_loop(t_context *context);
int	is_stack_insertable(t_stack *receiver, t_stack *inserted);
#endif
