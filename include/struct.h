/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:00:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/27 19:33:19 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "libft.h"

//------------------------------------------------- 
//                    Forward Declarations
//------------------------------------------------- 

typedef struct s_node	t_node;
typedef struct s_target	t_target;
typedef struct s_context	t_context;

//------------------------------------------------- 
//					Target
//------------------------------------------------- 

typedef void	(*t_move)(t_context *context);

typedef struct s_target
{
	t_node	*target_node;
	t_list	*movelist;
	size_t	cost;
}	t_target;

//------------------------------------------------- 
//					Nodes
//------------------------------------------------- 

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	t_target		target;
}	t_node;
//------------------------------------------------- 
//					Stack
//------------------------------------------------- 

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
	int		high;
	int		low;
}	t_stack;

//------------------------------------------------- 
//					Context
//------------------------------------------------- 

typedef struct s_context
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*array;
	t_list	*end_mvlist;
}	t_context;


#endif
