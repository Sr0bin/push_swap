/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:31:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/13 04:30:24 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	// t_context *context;
	t_stack *stack;
	(void) argc;
	(void) argv;
	size_t	counter;

	counter = 10;
	while (counter == 10)
	{
		stack = fake_stack(counter++);
		print_stack(stack);
		rotate_stack(stack);
		// reverse_rotate_stack(stack);
		print_stack(stack);
		free_stack(stack);
	}
	return (0);
}
