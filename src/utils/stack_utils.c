/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:52 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/27 17:24:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(t_node *node)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		error_handling(MEM_ERROR, NULL);
	stack->top = node;
	if (node == NULL)
	{
		stack->size = 0;
		stack->high = 0;
		stack->low = 0;
	}
	else
	{
		stack->size = 1;
		stack->high = node->value;
		stack->low = node->value;
	}
	return (stack);
}

void	stack_add_node(t_stack *stack, t_node *node)
{
	if (stack == NULL || node == NULL)
		return ;
	if (stack->top == NULL)
	{
		node->prev = node;
		node->next = node;
		stack->low = node->value;
		stack->high = node->value;
	}
	else
		push_node(stack->top, node);
	stack->top = node;
	stack->size++;
	if (node->value > stack->high)
		stack->high = node->value;
	if (node->value < stack->low)
		stack->low = node->value;
}

t_node	*stack_remove_node(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL)
		return (NULL);
	temp = stack->top;
	stack->top = temp->prev;
	pop_node(temp);
	stack->size--;
	if (stack->size == 0)
		stack->top = NULL;
	stack->high = stack_highest(stack);
	stack->low = stack_lowest(stack);
	return (temp);
}

void	free_stack(t_stack **stack)
{
	t_node	*node;

	if (*stack == NULL)
		return ;
	while ((*stack)->size > 0)
	{
		node = stack_remove_node(*stack);
		free_node(&node);
	}
	free(*stack);
	*stack = NULL;
}
