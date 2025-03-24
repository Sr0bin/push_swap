/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:31:32 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/24 17:31:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_highest(t_stack *stack)
{
	size_t	counter;
	t_node	*current_node;
	int		highest;

	counter = 0;
	current_node = stack->top;
	highest = stack->high;
	while (counter++ < stack->size)
	{
		if (current_node->value > highest)
			highest = current_node->value;
		current_node = current_node->prev;
	}
	return (highest);
}

int	stack_lowest(t_stack *stack)
{
	size_t	counter;
	t_node	*current_node;
	int		lowest;

	counter = 0;
	current_node = stack->top;
	lowest = stack->low;
	while (counter++ < stack->size)
	{
		if (current_node->value < lowest)
			lowest = current_node->value;
		current_node = current_node->prev;
	}
	return (lowest);
}

