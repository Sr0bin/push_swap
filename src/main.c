/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:31:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/24 17:59:17 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "error.h"
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_context *context;
	// t_list	*movelist;
	// t_list	*movelist2;
	
	// stack_test();
	// context_test();
	// parsing_test();
	// movelist = NULL;
	// movelist2 = NULL;
	context = context_init(argc, argv); 
	print_context(context);
	stack_a_loop(context);
	print_context(context);
	free_context(&context);
	// algo_test(context);
	
	/*inserted_test();*/
	/*sorting_test(context);*/
	// movelist_test();
	// movelist_add_n(&movelist, pa, 1);
	// movelist_add_n(&movelist2, ra, 1);
	// append_movelist(context, movelist);
	// append_movelist(context, movelist2);
	// print_movelist(context->final_movelist);
	return (EXIT_SUCCESS);
}
