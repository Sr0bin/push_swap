/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:31:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/15 19:23:48 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_context *context;
	
	// stack_test();
	// context_test();
	// parsing_test();
	context = context_init(argc, argv); 
	print_stack(context->stack_a);
	print_stack(context->stack_b);
	algo_test(context);
	free_context(&context);
	// movelist_test();
	return (EXIT_SUCCESS);
}
