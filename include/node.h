/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:05:15 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/28 03:06:03 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H
# include "struct.h"

//------------------------------------------------- 
//					Nodes
//------------------------------------------------- 

t_node	*node_init(int value);
void	push_node(t_node *head, t_node *new);
void	pop_node(t_node *node);
void	free_node(t_node **node);

#endif
