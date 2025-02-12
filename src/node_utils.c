/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:53:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/12 23:09:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(int value)
{
	t_node *node;
	node = ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->previous = node;
	node->next = node;
	node->value = value;
	return (node);
}

void	free_node(t_node *node)
{
	if (node == NULL)
		return ;
	node->next->previous = NULL;
	node->next = NULL;
	free(node);
	node = NULL;
}
