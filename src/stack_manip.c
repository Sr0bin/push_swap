/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:01:04 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/24 17:27:42 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_stack(t_stack *n)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!n || !n->top || n->top == n->top->prev)
        return ;
	first = n->top;
	second = first->prev;
	if (n->size == 2)
	{
		n->top = n->top->next;
		return ;
	}
	last = first->next;
	second->prev->next = first;
	first->next = second;
	first->prev = second->prev;
	second->next = last;
	second->prev = first;
	last->prev = second;
	n->top = second;
}

void	push_stack(t_stack *giver, t_stack *receiver)
{
	if (giver->top == NULL)
		return ;
	stack_add_node(receiver, stack_remove_node(giver));
}
void	rotate_stack(t_stack *n)
{
	if (n == NULL || n->top == NULL || n->size < 2)
		return ;
	n->top = n->top->prev;
}
void	reverse_rotate_stack(t_stack *n)
{
	if (n == NULL || n->top == NULL || n->size < 2)
		return ;
	n->top = n->top->next;
}
