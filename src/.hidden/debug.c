/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:21:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/26 13:36:18 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	p_stack(const t_stack *stack)
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
	printf("Stack size = %zu | Highest : %d | Lowest : %d\n", stack->size, stack->high, stack->low);
	while (counter != 0 && temp != NULL && temp->prev != NULL && temp->next != NULL)
	{
		p_node(temp);
		temp = temp->prev;
		counter--;
	}
}
void	p_node(t_node *node)
{
		if (node == NULL)
		{
			printf("(null) Node\n");
			return ;

		}
		printf("-----------------------------------------------------\n");
		printf("Node with value : %i\n Address : %p \n Next : %p \n Previous : %p\n", 
		 node->value, node, node->next, node->prev);
}
void	p_target(t_node *node)
{
	printf("-----------------------------------------------------\n");
	printf("Node : \n");
	p_node(node);
	printf("-----------------------------------------------------\n");
	printf("Targeting Node : \n");
	p_node(node->target.target_node);
	printf("-----------------------------------------------------\n");
	printf("With Movelist : \n");
	print_movelist(node->target.movelist);
}
void	p_array(int	*array)
{
	int	counter;

	counter = 0;
	while(counter <= array[0])
	{
		printf("Array index %d : \n Array value : %d \n", counter, array[counter]);
		counter++;
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

void	p_context(t_context *context)
{
	printf("-----------------------------------------------------\n");
	printf("Stack A\n");
	printf("-----------------------------------------------------\n");
	p_stack(context->stack_a);
	printf("-----------------------------------------------------\n");
	printf("Stack B\n");
	printf("-----------------------------------------------------\n");
	p_stack(context->stack_b);
}

t_context	*fake_context(size_t a, size_t b)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_context	*context;

	stack_a = fake_stack(a);
	context = NULL;
	stack_b = fake_stack(b);
	context = context_init_debug(stack_a, stack_b);
	if (context == NULL)
		return (NULL);
	return (context);
}
