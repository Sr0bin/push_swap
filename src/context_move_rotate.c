/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_moves_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:47:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/26 21:06:02 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_context *context)
{
	if (context == NULL)
		return ;
	rotate_stack(context->stack_a);
}
void	rb(t_context *context)
{
	if (context == NULL)
		return ;
	rotate_stack(context->stack_b);
}
void	rr(t_context *context)
{
	if (context == NULL)
		return ;
	rotate_stack(context->stack_a);
	rotate_stack(context->stack_b);
}
