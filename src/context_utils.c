/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:29:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/12 23:11:49 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_context	*context_init()
{
	t_context	*context;
	context = ft_calloc(1, sizeof(t_context));
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
int	main(void)
{
	t_context context;
	const t_move func_moves[11] = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
	func_moves[SA](&context);
}
