/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:53:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/21 12:18:19 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		error_handling(MEM_ERROR, NULL);
	node->previous = node;
	node->next = node;
	node->value = value;
	node->target = target_init();
	return (node);
}

void	push_node(t_node *head, t_node *new)
{
	t_node	*next_node;

	if (head == NULL || new == NULL)
		return ;
	next_node = head->next;
	head->next = new;
	new->next = next_node;
	new->previous = head;
	next_node->previous = new;
}
void	pop_node(t_node *node)
{
	if (node == NULL)
		return ;
	node->previous->next = node->next;
	node->next->previous = node->previous;
	node->next = NULL;
	node->previous = NULL;
}

void	free_node(t_node **node)
{
	// free_target(&((*node)->target));
	if (*node == NULL)
		return ;
	if ((*node)->previous != NULL)
		(*node)->previous->next = NULL;
	if ((*node)->next != NULL)
		(*node)->next->previous = NULL;
	free(*node);
	*node = NULL;
}
