/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:20:41 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 11:19:22 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack->size == 1)
		return (1);
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

t_node	*is_stack_insertable(t_stack *receiver, t_stack *ins)
{
	t_node	*temp;
	size_t	counter;
	int		sort_a;
	int		sort_b;

	temp = receiver->top;
	counter = 0;
	if (receiver->size == 1)
		return (receiver->top);
	sort_a = is_stack_sorted(receiver);
	sort_b = is_stack_sorted(ins);
	if (sort_a != 1 || sort_b != -1)
		return (NULL);
	if (ins->low > receiver->high)
		return (find_node(receiver, receiver->low));
	if (receiver->low > ins->high)
		return (find_node(receiver, receiver->high));
	while (counter++ < receiver->size)
	{
		if (ins->high < temp->value && ins->low > temp->prev->value)
			return (temp);
		temp = temp->prev;
	}
	return (NULL);
}
