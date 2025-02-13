/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:52 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/13 05:11:50 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(t_node *node)
{
	t_stack	*stack;

	if (node == NULL)
		return (NULL);
	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = node;
	stack->size = 1;
	return (stack);
}

void	stack_add_node(t_stack *stack, t_node *node)
{
	if (stack == NULL || node == NULL)
		return ;
	push_node(stack->top, node);
	stack->top = node;
	stack->size++;
}

t_node	*stack_remove_node(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL)
		return (NULL);
	temp = stack->top;
	stack->top = temp->previous;
	pop_node(temp);
	return (temp);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	temp = NULL;
	if (stack == NULL)
		return ;
	while (stack->top != NULL && stack->top->next != NULL)
	{
		if (stack->top->next != stack->top)
			temp = stack->top->next;
		else
			temp = NULL;
		free_node(stack->top);
		stack->top = temp;
	}
	free_node(stack->top);
	free(stack);
	stack = NULL;
}
