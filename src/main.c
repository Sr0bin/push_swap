/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:31:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/13 05:00:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_test(void)
{
	
	t_stack *stack_a;
	t_stack *stack_b;
	stack_a = fake_stack(10);
	stack_b = fake_stack(0);
	print_stack(stack_a);
	print_stack(stack_b);
	push_stack(stack_b, stack_a);
	// free(stack_remove_node(stack_a));
	// rotate_stack(stack);
	// reverse_rotate_stack(stack);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
void	context_test(void)
{
	t_context *context;
	
	context = fake_context();
	print_context(context);
	pb(context);
	print_context(context);
	free_context(context);
}
int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	stack_test();
	return (0);
}
