/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:53:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/27 17:23:52 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		error_handling(MEM_ERROR, NULL);
	node->prev = node;
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
	new->prev = head;
	next_node->prev = new;
}
void	pop_node(t_node *node)
{
	if (node == NULL)
		return ;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
}

void	free_node(t_node **node)
{
	if (*node == NULL)
		return ;
	if ((*node)->prev != NULL)
		(*node)->prev->next = NULL;
	if ((*node)->next != NULL)
		(*node)->next->prev = NULL;
	free(*node);
	*node = NULL;
}
