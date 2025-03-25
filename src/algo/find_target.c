/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:07:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/25 18:45:46 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "movelist.h"
#include "push_swap.h"
#include <stdio.h>

int	depth_node(t_stack stack, t_node *node)
{
	int	counter;

	counter = 0;
	while (counter < (int) stack.size)
	{
		if (stack.top == node)
			return (counter);
		stack.top = stack.top->prev;
		counter++;
	}
	return (-1);

}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current_node;
	size_t	counter;
	int		sorting_state;
	
	current_node = stack->top;
	counter = 0;
	sorting_state = 0;
	if (current_node == NULL)
		return (0);
	while (counter++ < stack->size)
	{
		if (current_node->value < current_node->prev->value)
			sorting_state++;
		if (current_node->value > current_node->prev->value)
			sorting_state--;
		current_node = current_node->prev;
	}
	if (sorting_state == (int) stack->size - 2)
		return (1);
	if (sorting_state == -((int) stack->size - 2))
		return (-1);
	return (0);
}

int	is_stack_insertable(t_stack *receiver, t_stack *ins)
{
	t_node	*current_node;
	size_t	counter;
	int		sort_a;
	int		sort_b;

	current_node = receiver->top;
	counter = 0;
	sort_a = is_stack_sorted(receiver); 
	sort_b = is_stack_sorted(ins); 
	if (!(sort_a * sort_b == -1))
		return (0);
	if (receiver->high < ins->low || ins->high < receiver->low)
		return (1);
	while (counter++ < receiver->size)
	{
		if (ins->high < current_node->value && ins->low > current_node->prev->value)
			return (1);
		current_node = current_node->prev;
	}
	return (0);
}

/*void	algo_loop(t_context *context)*/
/*{*/
/**/
/*	while (is_stack_sorted(context->stack_a) != 1)*/
/*	{*/
/**/
/*	}*/
/*}*/

t_node	*find_target_inside(t_context context, t_node *node)
{
	t_node	*target_node;
	size_t	counter;

	target_node = context.stack_b->top;
	counter = 0;
	while (counter++ < context.stack_b->size)
	{
		if (node->value > target_node->value && node->value < target_node->next->value)
			break;
		target_node = target_node->prev;
	}
	return (target_node);
}

t_node	*find_target_new_HL(t_context context, t_node *node)
{
	t_node	*target_node;
	size_t	counter;
	(void) node;

	target_node = context.stack_b->top;
	counter = 0;
	while (counter++ < context.stack_b->size)
	{
		if (target_node->value > target_node->next->value)
			break;
		target_node = target_node->prev;
	}
	return (target_node);
}
void	find_target(t_context context, t_node *node)
{
	t_node	*target_node;
	int		depth_a;
	int		depth_b;

	if (context.stack_b->size == 0)
	{
		movelist_add_n(&(node->target.movelist), pb, 1);
		node->target.cost = 1;
		return ;
	}
	depth_a = depth_node(*(context.stack_a), node);
	target_node = context.stack_b->top;
	if (node->value > context.stack_b->high || node->value < context.stack_b->low )
		target_node = find_target_new_HL(context, node);
	else
		target_node = find_target_inside(context, node);
	depth_b  = depth_node(*(context.stack_b), target_node);
	free_target(&(node->target));
	movelist_add_n(&(node->target.movelist), ra, (size_t) depth_a);
	movelist_add_n(&(node->target.movelist), rb, (size_t) depth_b);
	movelist_add_n(&(node->target.movelist), pb, 1);
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
		current_node = current_node->prev;
	}
}

void	apply_best_moves(t_context *context)
{
	t_node	*temp_node;
	t_node	*best_node;
	size_t	counter;

	temp_node = context->stack_a->top;
	best_node = temp_node;
	counter = 0;
	while (counter++ < context->stack_a->size)
	{
		if (temp_node->target.cost < best_node->target.cost)
		{
			best_node = temp_node;
		}
		temp_node = temp_node->prev;
	}
	/*print_target(best_node);*/
	append_movelist(context, best_node->target.movelist);
	apply_movelist(context, best_node->target.movelist);
	/*print_context(context);*/
	/*print_movelist(movelist);*/
	/*print_movelist(context->final_movelist);*/
}

void	stack_a_loop(t_context *context)
{
	while (context->stack_a->top != NULL)
	{
		/*print_context(context);*/
		update_stack_target(context);
		apply_best_moves(context);
	}
	movelist_add_n(&context->final_movelist, pa, context->stack_b->size);
	print_movelist(context->final_movelist);
}
