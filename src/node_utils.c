/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:53:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/13 00:46:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(void)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->previous = node;
	node->next = node;
	// node->value = value;
	return (node);
}

void	push_node(t_node *head, t_node *new)
{
	t_node	*temp;

	if (head == NULL || new == NULL)
		return ;
	temp = head->next;
	head->next = new;
	new->previous = head;
	temp->previous = new;
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

void	free_node(t_node *node)
{
	if (node == NULL)
		return ;
	node->next->previous = NULL;
	free(node);
	node = NULL;
}
