/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_move_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:49:07 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/12 22:49:47 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_context *context)
{
	push_stack(context->stack_a, context->stack_b);
}
void	pb(t_context *context)
{
	push_stack(context->stack_b, context->stack_a);
}
