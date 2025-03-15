/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_move_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:47:42 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/26 22:28:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_context *context)
{
	if (context == NULL)
		return ;
	reverse_rotate_stack(context->stack_a);
}

void	rrb(t_context *context)
{
	if (context == NULL)
		return ;
	reverse_rotate_stack(context->stack_b);
}

void	rrr(t_context *context)
{
	if (context == NULL)
		return ;
	reverse_rotate_stack(context->stack_a);
	reverse_rotate_stack(context->stack_b);
}
