/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:21:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/14 03:40:08 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(const t_stack *stack)
{
	size_t	counter;
	t_node	*temp;
	if (stack == NULL)
	{
		printf("Stack is (NULL)");
		return ;
	}
	counter = stack->size;
	temp = stack->top;
	printf("-----------------------------------------------------\n");
	printf("Stack size = %zu\n", stack->size);
	while (counter != 0 && temp != NULL && temp->previous != NULL && temp->next != NULL)
	{
		printf("-----------------------------------------------------\n");
		printf("Node with value : %i\n Address : %p \n Next : %p \n Previous : %p\n", 
		 temp->value, temp, temp->next, temp->previous);
		temp = temp->previous;
		counter--;
	}
}
t_stack	*fake_stack(size_t n)
{
	t_stack	*stack;
	t_node	*temp;
	size_t	counter;
	
	counter = 1;
	stack = stack_init(node_init((int)counter));
	while (counter < n)
	{
		counter++;
		temp = node_init((int)counter);
		stack_add_node(stack, temp);
		// printf("Created node with value : %i, next  = %i, previous = %i, stack pointing to :%i\n", \
		 //temp->value, temp->next->value, temp->previous->value, stack->top->value);
	}
	return (stack);
}

void	print_context(t_context *context)
{
	printf("-----------------------------------------------------\n");
	printf("Stack A\n");
	printf("-----------------------------------------------------\n");
	print_stack(context->stack_a);
	printf("-----------------------------------------------------\n");
	printf("Stack B\n");
	printf("-----------------------------------------------------\n");
	print_stack(context->stack_b);
}

t_context	*fake_context(size_t a, size_t b)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_context	*context;

	stack_a = fake_stack(a);
	stack_b = fake_stack(b);
	context = context_init(stack_a, stack_b);
	if (context == NULL)
		return (NULL);
	return (context);
}
