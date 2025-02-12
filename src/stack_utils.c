/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:52 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/12 23:10:20 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(t_node *node)
{
	t_stack *stack;
	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = node;
	stack->size = 1;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	temp = NULL;
	if (stack == NULL)
		return ;
	while (stack->top->next != NULL)
	{
		temp = stack->top->next;
		free_node(stack->top);
		stack->top = temp;
	}
	free_node(stack->top);
	free(stack);
}

void	swap_top_stack(t_stack *n);
void	push_stack(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *n);
void	reverse_rotate_stack(t_stack *n);
void	reverse_rotate_stack(t_stack *n);
