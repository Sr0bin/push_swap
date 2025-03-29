/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:22:06 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/29 14:52:30 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*find_node(t_stack *stack, int value)
{
	size_t	counter;
	t_node	*current_node;

	counter = 0;
	current_node = stack->top;
	while (counter++ < stack->size)
	{
		if (current_node->value == value)
			return (current_node);
		current_node = current_node->prev;
	}
	return (NULL);
}
