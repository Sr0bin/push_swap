/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:23:10 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 12:33:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_list	*temp;
	size_t	c_ra;
	size_t	c_rb;

	temp = *start;
	c_ra = 0;
	c_rb = 0;
	while (temp != NULL && (temp->content == ra || temp->content == rb))
	{
		if (temp->content == ra)
			c_ra++;
		else if (temp->content == rb)
			c_rb++;
		temp = temp->next;
	}
	if (c_ra > 0 && c_rb > 0)
	{
		if (c_ra > c_rb)
		{
			temp = node_n(*start, c_ra - c_rb - 1);
			temp->next = mvlist_replace_n(&temp->next, rr, c_rb, c_rb * 2);
		}
		else
			mvlist_replace_n(start, rr, c_ra, c_ra * 2);
	}
}

void	replace_rra_rrb(t_list **start)
{
	t_list	*temp;
	size_t	c_rra;
	size_t	c_rrb;

	temp = *start;
	c_rra = 0;
	c_rrb = 0;
	while (temp != NULL && (temp->content == rra || temp->content == rrb))
	{
		if (temp->content == rra)
			c_rra++;
		else if (temp->content == rrb)
			c_rrb++;
		temp = temp->next;
	}
	if (c_rra > 0 && c_rrb > 0)
	{
		if (c_rra > c_rrb)
		{
			temp = node_n(*start, c_rra - c_rrb - 1);
			temp->next = mvlist_replace_n(&temp->next, rrr, c_rrb, c_rrb * 2);
		}
		else
			mvlist_replace_n(start, rrr, c_rra, c_rra * 2);
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

void	shortest_rotate(t_context c, t_stack *s, t_node *node, t_list **mv_lst)
{
	int	depth;

	depth = depth_node(*s, node);
	if (depth == -1)
		return ;
	if (depth == 0)
		return ;
	if (depth <= (int) s->size / 2)
	{
		if (s == c.stack_a)
			movelist_add_n(mv_lst, ra, (size_t) depth);
		else
			movelist_add_n(mv_lst, rb, (size_t) depth);
	}
	else
	{
		if (s == c.stack_a)
			movelist_add_n(mv_lst, rra, (s->size - (size_t) depth));
		else
			movelist_add_n(mv_lst, rrb, (s->size - (size_t) depth));
	}
}
