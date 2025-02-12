/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:29:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/12 23:34:26 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_context	*context_init(void)
{
	t_context	*context;

	context = ft_calloc(1, sizeof(t_context));
	context->stack_a = stack_init(node_init());
	if (context->stack_a == NULL)
	{
		free(context);
		return (NULL);
	}
	context->stack_b = stack_init(node_init());
	if (context->stack_b == NULL)
	{
		free_stack(context->stack_a);
		free(context);
		return (NULL);
	}
	return (context);
}
void	free_context(t_context *context)
{
	if (context == NULL)
		return ;
	free_stack(context->stack_a);
	free_stack(context->stack_a);
	free(context);
}
//
//
// int	main(void)
// {
// 	t_context context;
// 	const t_move func_moves[11] = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
// 	func_moves[SA](&context);
// }
