/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:07:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/15 20:55:00 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_node	*target;
	int		depth_a;
	int		depth_b;
	size_t	diff;

	depth_a = depth_node(*(context.stack_a), node);
	target = context.stack_b->top;
	while (target->value <= node->value)
		target = target->previous;
	depth_b  = depth_node(*(context.stack_b), target);
	if (depth_a < (int) context.stack_a->size / 2)
	{
		if (depth_a >= depth_b)
		{
			movelist_add_n(&(node->target.movelist), rr, (size_t) depth_b);
			movelist_add_n(&(node->target.movelist), ra, (size_t) (depth_a - depth_b));
		} 
		else
		{
			movelist_add_n(&(node->target.movelist), rr, (size_t) depth_a);
			movelist_add_n(&(node->target.movelist), rb, (size_t) (depth_b - depth_a));
		}
	}
	else
	{
		if (depth_a >= depth_b)
		{
			movelist_add_n(&(node->target.movelist), rrr, (context.stack_b->size - (size_t) depth_b));
			movelist_add_n(&(node->target.movelist), rra, (size_t) (depth_a - depth_b));
		} 
		else
		{
			movelist_add_n(&(node->target.movelist), rrr, (size_t) depth_a);
			movelist_add_n(&(node->target.movelist), rrb, (size_t) (depth_b - depth_a));
		}
	}


}

