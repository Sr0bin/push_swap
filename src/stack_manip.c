/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:01:04 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/13 04:28:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_stack(t_stack *n)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = n->top;
	second = first->previous;
	last = first->next;
	second->previous->next = first;
	first->next = second;
	first->previous = second->previous;
	second->next = last;
	second->previous = first;
	last->previous = second;
	n->top = second;
}
void	push_stack(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *n)
{
	n->top = n->top->previous;
}
void	reverse_rotate_stack(t_stack *n)
{
	n->top = n->top->next;
}
