/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:00:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/28 03:53:50 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "libft.h"

//------------------------------------------------- 
//					Nodes
//------------------------------------------------- 

typedef struct s_node
{
	struct s_node	*previous;
	struct s_node	*next;
	int				value;
}	t_node;
//------------------------------------------------- 
//					Stack
//------------------------------------------------- 

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;

//------------------------------------------------- 
//					Context
//------------------------------------------------- 

typedef struct s_context
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*array;
}	t_context;

#endif
