/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_move_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:49:07 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/24 19:44:30 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_context *context)
{
	if (context == NULL)
		return ;
	push_stack(context->stack_b, context->stack_a);
}

void	pb(t_context *context)
{
	if (context == NULL)
		return ;
	push_stack(context->stack_a, context->stack_b);
}
