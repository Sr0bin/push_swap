/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:21:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/13 04:15:29 by rorollin         ###   ########.fr       */
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
	while (counter != 0)
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
		printf("Created node with value : %i, next  = %i, previous = %i, stack pointing to :%i\n", \
		 temp->value, temp->next->value, temp->previous->value, stack->top->value);
	}
	return (stack);
}
