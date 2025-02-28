/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:06:22 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/28 03:07:02 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "struct.h"
//------------------------------------------------- 
//					Stack
//------------------------------------------------- 

t_stack	*stack_init(t_node *node);
void	stack_add_node(t_stack *stack, t_node *node);
t_node	*stack_remove_node(t_stack *stack);
void	free_stack(t_stack **stack);
void	swap_top_stack(t_stack *n);
void	push_stack(t_stack *giver, t_stack *receiver);
void	rotate_stack(t_stack *n);
void	reverse_rotate_stack(t_stack *n);

#endif
