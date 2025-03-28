/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:23:10 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 08:50:35 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "list.h"
#include "push_swap.h"

t_list	*node_n(t_list *node, size_t n)
{
	size_t	counter;

	counter = 0;
	while (node != NULL && counter++ < n)
		node = node->next;
	return (node);
}

void	replace_ra_rb(t_list **start)
{
	t_list	*current;
	size_t	count_ra;
	size_t	count_rb;

	current = *start;
	count_ra = 0;
	count_rb = 0;
	while (current != NULL && (current->content == ra || current->content == rb))
	{
		if (current->content == ra)
			count_ra++;
		else if (current->content == rb)
			count_rb++;
		current = current->next;
	}
	if (count_ra > 0 && count_rb > 0)
	{
		if (count_ra > count_rb)
		{
			current = node_n(*start, count_ra - count_rb - 1);
			current->next = mvlist_replace_n(&current->next, rr, count_rb, count_rb * 2);
		}
		else
			mvlist_replace_n(start, rr, count_ra, count_ra * 2);
	}
}

void	replace_rra_rrb(t_list **start)
{
	t_list	*current;
	size_t	count_rra;
	size_t	count_rrb;

	current = *start;
	count_rra = 0;
	count_rrb = 0;
	while (current != NULL && (current->content == rra || current->content == rrb))
	{
		if (current->content == rra)
			count_rra++;
		else if (current->content == rrb)
			count_rrb++;
		current = current->next;
	}
	if (count_rra > 0 && count_rrb > 0)
	{
		if (count_rra > count_rrb)
		{
			current = node_n(*start, count_rra - count_rrb - 1);
			current->next = mvlist_replace_n(&current->next, rrr, count_rrb, count_rrb * 2);
		}
		else
			mvlist_replace_n(start, rrr, count_rra, count_rra * 2);
	}
}

void	optimize_movelist(t_list **movelist)
{
	t_list	**current;

	if (movelist == NULL || *movelist == NULL)
		return ;
	current = movelist;
	while (*current != NULL)
	{
		replace_ra_rb(current);
		replace_rra_rrb(current);
		if (*current != NULL)
			current = &(*current)->next;
	}
}

void	shortest_rotate(t_context context, t_stack *stack, t_node *node, t_list **movelist)
{
	int	depth;

	depth = depth_node(*stack, node);
	if (depth == -1)
		return ;
	if (depth == 0)
		return ;
	if (depth <= (int) stack->size / 2)
	{
		if (stack == context.stack_a)
			movelist_add_n(movelist, ra, (size_t) depth);
		else
			movelist_add_n(movelist, rb, (size_t) depth);
	}
	else
	{
		if (stack == context.stack_a)
			movelist_add_n(movelist, rra, (stack->size - (size_t) depth));
		else
			movelist_add_n(movelist, rrb, (stack->size - (size_t) depth));
	}
}
