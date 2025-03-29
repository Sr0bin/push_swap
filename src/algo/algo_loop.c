/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:24:20 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/29 19:49:38 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		/*current_node->target = target_init();*/
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
	apply_apnd_mvlist(context, &best_node->target.movelist);
}

void	stack_a_loop(t_context *cont)
{
	t_node	*current_node;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*mv_lst;

	stack_a = cont->stack_a;
	stack_b = cont->stack_b;
	mv_lst = NULL;
	while (cont->stack_a->top != NULL && cont->stack_a->size > 1)
	{
		update_stack_target(cont);
		apply_best_moves(cont);
	}
	free_movelist(&stack_a->top->target.movelist);
	if (stack_a->top->value > stack_b->high || \
		stack_a->top->value < stack_b->low)
		current_node = find_target_new_hl(stack_b, stack_a->top);
	else
		current_node = find_target_inside(stack_b, stack_a->top);
	shortest_rotate(*cont, stack_b, current_node, &mv_lst);
	movelist_add_n(&mv_lst, pa, stack_b->size);
	apply_apnd_mvlist(cont, &mv_lst);
	shortest_rotate(*cont, stack_a, find_node(stack_a, stack_a->low), &mv_lst);
	append_movelist(cont, mv_lst);
	optimize_movelist(&cont->end_mvlist);
}

void	sort_three(t_context *context)
{
	t_node	*top;
	int		second;
	int		third;
	t_list	*movelist;

	top = context->stack_a->top;
	second = top->prev->value;
	third = top->prev->prev->value;
	movelist = NULL;
	if (top->value > second && third > second && third > top->value)
		movelist_add_n(&movelist, sa, 1);
	else if (top->value > second && third > second && top->value > third)
		movelist_add_n(&movelist, ra, 1);
	else if (top->value < second && third < second && top->value > third)
		movelist_add_n(&movelist, rra, 1);
	else if (top->value < second && third < second && top->value < third)
		movelist_add_sa_ra(&movelist);
	else if (top->value > second && third < second && top->value > third)
	{
		movelist_add_n(&movelist, sa, 1);
		movelist_add_n(&movelist, rra, 1);
	}
	apply_apnd_mvlist(context, &movelist);
}

void	dumb_sort(t_context *context)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_list	*movelist;

	stk_a = context->stack_a;
	stk_b = context->stack_b;
	if (is_stack_sorted(stk_a) == 1)
	{
		shortest_rotate(*context, stk_a, \
				find_node(stk_a, stk_a->low), &(context->end_mvlist));
		return ;
	}
	while (context->stack_a->size > 3)
	{
		movelist = NULL;
		shortest_rotate(*context, stk_a, \
					find_node(stk_a, stk_a->low), &movelist);
		movelist_add_n(&movelist, pb, 1);
		apply_apnd_mvlist(context, &movelist);
	}
	movelist = NULL;
	sort_three(context);
	shortest_rotate(*context, stk_b, find_node(stk_b, stk_b->high), &movelist);
	movelist_add_n(&movelist, pa, stk_b->size);
	apply_apnd_mvlist(context, &movelist);
}
