/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_move_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:48:43 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/26 21:06:02 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_context *context)
{
	if (context == NULL)
		return ;
	swap_top_stack(context->stack_a);
}
void	sb(t_context *context)
{
	if (context == NULL)
		return ;
	swap_top_stack(context->stack_b);
}
void	ss(t_context *context)
{
	if (context == NULL)
		return ;
	swap_top_stack(context->stack_a);
	swap_top_stack(context->stack_b);
}
