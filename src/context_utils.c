/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:29:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/14 06:22:17 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_context	*context_init(t_stack *stack_a, t_stack *stack_b)
{
	t_context	*context;

	if (stack_a == NULL || stack_b == NULL)
		return (NULL);
	context = ft_calloc(1, sizeof(t_context));
	if	(context == NULL)
		return (NULL);
	context->stack_a = stack_a;
	context->stack_b = stack_b;
	// context->stack_a = stack_init(node_init(0));
	// if (context->stack_a == NULL)
	// {
	// 	free(context);
	// 	return (NULL);
	// }
	// context->stack_b = stack_init(node_init(0));
	// if (context->stack_b == NULL)
	// {
	// 	free_stack(context->stack_a);
	// 	free(context);
	// 	return (NULL);
	// }
	return (context);
}

void	free_context(t_context **context)
{
	if (context == NULL || *context == NULL)
		return ;
	free_stack(&(*context)->stack_a);
	free_stack(&(*context)->stack_b);
	free(*context);
	*context = NULL;
}

//
// int	main(void)
// {
// 	t_context context;
// 	const t_move func_moves[11] = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
// 	func_moves[SA](&context);
// }
