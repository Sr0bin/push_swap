/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:07:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/21 19:33:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "movelist.h"
#include "push_swap.h"

int	depth_node(t_stack stack, t_node *node)
{
	int	counter;

	counter = 0;
	while (counter <= (int) stack.size)
	{
		if (stack.top == node)
			return (counter);
		stack.top = stack.top->previous;
		counter++;
	}
	return (-1);

}

void	find_target(t_context context, t_node *node)
{
	t_node	*target_node;
	int		depth_a;
	int		depth_b;
	size_t	counter;

	depth_a = depth_node(*(context.stack_a), node);
	target_node = context.stack_b->top;
	counter = 0;
	while (target_node != NULL && target_node->value <= node->value && counter < context.stack_b->size)
	{
		target_node = target_node->previous;
		counter++;
	}
	depth_b  = depth_node(*(context.stack_b), target_node);
	free_target(&(node->target));
	movelist_add_n(&(node->target.movelist), ra, (size_t) depth_a);
	movelist_add_n(&(node->target.movelist), rb, (size_t) depth_b);
	movelist_add_n(&(node->target.movelist), pa, 1);
	node->target.cost = (size_t) (depth_a + depth_b + 1);
	node->target.target_node = target_node;
}

void	update_stack_target(t_context *context)
{
	size_t	counter;
	t_stack	*stack_a;
	t_node	*current_node;

	counter = 0 ;
	stack_a = context->stack_a;
	current_node = stack_a->top;
	while (counter++ < stack_a->size)
	{
		find_target(*context, current_node);
		current_node = current_node->previous;
	}
}

void	apply_best_moves(t_context *context)
{
	t_node	*current_node;
	size_t	cost;
	t_list	*movelist;
	size_t	counter;

	current_node = context->stack_a->top;
	cost = current_node->target.cost;
	movelist = current_node->target.movelist;
	counter = 0;
	while (counter++ < context->stack_a->size)
	{
		if (current_node->target.cost < cost)
		{
			cost = current_node->target.cost;
			movelist = current_node->target.movelist;
		}
		current_node = current_node->previous;
	}
	append_movelist(context, movelist);
	apply_movelist(context, movelist);
}

void	stack_a_loop(t_context *context)
{
	while (context->stack_a->top != NULL)
	{
		update_stack_target(context);
		apply_best_moves(context);
	}
	print_movelist(context->final_movelist);
}
