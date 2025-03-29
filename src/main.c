/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:31:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 12:33:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	*cont;
	t_node		*temp;

	if (argc == 1)
		return (0);
	cont = context_init(argc, argv);
	if (cont->stack_a == NULL)
		error_handling(ARG_NAN, NULL);
	if (is_stack_sorted(cont->stack_a) == 1)
	{
		temp = find_node(cont->stack_a, cont->stack_a->low);
		shortest_rotate(*cont, cont->stack_a, temp, &(cont->end_mvlist));
		print_movelist(cont->end_mvlist);
		free_context(&cont);
		return (EXIT_SUCCESS);
	}
	if (cont->stack_a->size <= 26)
		dumb_sort(cont);
	else
		stack_a_loop(cont);
	print_movelist(cont->end_mvlist);
	free_context(&cont);
	return (EXIT_SUCCESS);
}
  