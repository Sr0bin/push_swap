/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:07:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/29 18:55:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_target_inside(t_stack *stack, t_node *node)
{
	t_node	*trgt_n;
	size_t	counter;

	trgt_n = stack->top;
	counter = 0;
	while (counter++ < stack->size)
	{
		if (node->value > trgt_n->value && node->value < trgt_n->next->value)
			break ;
		trgt_n = trgt_n->prev;
	}
	return (trgt_n);
}

t_node	*find_target_final(t_stack *stack, t_node *node)
{
	t_node	*trgt_n;
	size_t	counter;

	trgt_n = stack->top;
	counter = 0;
	while (counter++ < stack->size)
	{
		if (node->value > trgt_n->value && node->value < trgt_n->next->value)
			break ;
		trgt_n = trgt_n->prev;
	}
	return (trgt_n);
}

t_node	*find_target_new_hl(t_stack *stack, t_node *node)
{
	t_node	*target_node;
	size_t	counter;

	(void) node;
	target_node = stack->top;
	counter = 0;
	while (counter++ < stack->size)
	{
		if (target_node->value > target_node->next->value)
			break ;
		target_node = target_node->prev;
	}
	return (target_node);
}

void	find_target(t_context cntxt, t_node *node)
{
	t_node	*target_node;

	if (cntxt.stack_b->size == 0)
		return ;
	target_node = cntxt.stack_b->top;
	if (node->value > cntxt.stack_b->high || node->value < cntxt.stack_b->low)
		target_node = find_target_new_hl(cntxt.stack_b, node);
	else
		target_node = find_target_inside(cntxt.stack_b, node);
	node->target.target_node = target_node;
}

void	find_best_moves(t_context context, t_node *node)
{
	if (context.stack_b->size == 0)
	{
		movelist_add_n(&(node->target.movelist), pb, 1);
		node->target.cost = 1;
		return ;
	}
	if (node->target.movelist != NULL)
		free_movelist(&(node->target.movelist));
	shortest_rotate(context, context.stack_a, node, &(node->target.movelist));
	shortest_rotate(context, context.stack_b, \
					node->target.target_node, &(node->target.movelist));
	movelist_add_n(&(node->target.movelist), pb, 1);
	node->target.cost = (size_t)(ft_lstsize(node->target.movelist));
}
