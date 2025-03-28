/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:24:20 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 09:38:36 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "context.h"
#include "movelist.h"
#include "push_swap.h"

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
		find_best_moves(*context, current_node);
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
	append_movelist(context, best_node->target.movelist);
	apply_movelist(context, best_node->target.movelist);
}

void	stack_a_loop(t_context *context)
{
	t_node	*current_node;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*movelist;

	stack_a = context->stack_a;
	stack_b = context->stack_b;
	if (is_stack_sorted(stack_a) == 1)
	{
		shortest_rotate(*context, stack_a, find_node(stack_a, stack_a->low), &(context->end_mvlist));
		return ;
	}
	while (context->stack_a->top != NULL && context->stack_a->size > 1)
	{
		update_stack_target(context);
		apply_best_moves(context);
	}
	free_movelist(&stack_a->top->target.movelist);
	if (stack_a->top->value > stack_b->high || stack_a->top->value < stack_b->low)
		current_node = find_target_new_hl(stack_b, stack_a->top);
	else
		current_node = find_target_inside(stack_b, stack_a->top);
	movelist = NULL;
	shortest_rotate(*context, stack_b, current_node, &movelist);
	movelist_add_n(&movelist, pa, stack_b->size);
	apply_movelist(context, movelist);
	append_movelist(context, movelist);
	movelist = NULL;
	shortest_rotate(*context, stack_a, find_node(stack_a, stack_a->low), &movelist);
	append_movelist(context, movelist);
	optimize_movelist(&context->end_mvlist);
}

void apply_apnd_mvlist(t_context *context, t_list **movelist)
{
	apply_movelist(context, *movelist);
	append_movelist(context, *movelist);
}

void	sort_three(t_context *context)
{
	int		first;
	int		second;
	int		third;
	t_list	*movelist;

	first = context->stack_a->top->value;
	second = context->stack_a->top->prev->value;
	third = context->stack_a->top->prev->prev->value;
	movelist = NULL;
	if (first > second && third > second && third > first)
		movelist_add_n(&movelist, sa, 1);
	else if (first > second && third > second && first > third)
		movelist_add_n(&movelist, ra, 1);
	else if (first < second && third < second && first > third)
		movelist_add_n(&movelist, rra, 1);
	else if (first < second && third < second && first < third)
	{
		movelist_add_n(&movelist, sa, 1);
		movelist_add_n(&movelist, ra, 1);
	}
	else if (first > second && third < second && first > third)
	{
		movelist_add_n(&movelist, sa, 1);
		movelist_add_n(&movelist, rra, 1);
	}
	apply_apnd_mvlist(context, &movelist);
}

void	sort_five(t_context *context)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_list	*movelist;

	stack_a = context->stack_a;
	stack_b = context->stack_b;
	if (is_stack_sorted(stack_a) == 1)
	{
		shortest_rotate(*context, stack_a, find_node(stack_a, stack_a->low), &(context->end_mvlist));
		return ;
	}
	while (context->stack_a->size > 3)
	{
		movelist = NULL;
		shortest_rotate(*context, stack_a, find_node(stack_a, stack_a->low), &movelist);
		movelist_add_n(&movelist, pb, 1);
		apply_apnd_mvlist(context, &movelist);
	}
	sort_three(context);
	movelist = NULL;
	shortest_rotate(*context, stack_b, find_node(stack_b, stack_b->high), &movelist);
	movelist_add_n(&movelist, pa, stack_b->size);
	apply_apnd_mvlist(context, &movelist);
}
