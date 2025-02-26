/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:52 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/14 06:22:04 by rorollin         ###   ########.fr       */
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
	stack->size--;
	if (stack->size == 0)
		stack->top = NULL;
	return (temp);
}
void free_stack(t_stack **stack)
{
    t_node	*node;

	if (*stack == NULL) 
		return;
    while ((*stack)->size > 0) 
	{
        node = stack_remove_node(*stack);
        free_node(&node);
    }
    free(*stack);
    *stack = NULL;
}
