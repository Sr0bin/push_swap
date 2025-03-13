/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:03:10 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/13 15:16:57 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# include "struct.h"
//------------------------------------------------- 
//					Context
//------------------------------------------------- 

t_context	*context_init(int argc, char **argv);
void		free_context(t_context **context);

//------------------------------------------------- 
//				Moves for context
//------------------------------------------------- 

void	sa(t_context *context);
void	sb(t_context *context);
void	ss(t_context *context);
void	pa(t_context *context);
void	pb(t_context *context);
void	ra(t_context *context);
void	rb(t_context *context);
void	rr(t_context *context);
void	rra(t_context *context);
void	rrb(t_context *context);
void	rrr(t_context *context);

typedef enum e_move_types
{
	SA,	//(swap a): Swap the first 2 elements at the top of stack a.
		//Do nothing if there is only one or no elements.
	SB,	//(swap b): Swap the first 2 elements at the top of stack b. 
		//Do nothing if there is only one or no elements.
	SS,	//: sa and sb at the same time.
	PA,	//Take the first element at the top of b and put it at the top of a. 
		//Do nothing if b is empty.
	PB,	//Take the first element at the top of a and put it at the top of b. 
		//Do nothing if a is empty.
	RA,	//(rotate a): Shift up all elements of stack a by 1. 
		//The first element becomes the last one.
	RB,	//(rotate b): Shift up all elements of stack b by 1. 
		//The first element becomes the last one.
	RR,	//: ra and rb at the same time.
	RRA,//(reverse rotate a): Shift down all elements of stack a by 1. 
		//The last element becomes the first one.
	RRB,//(reverse rotate b): Shift down all elements of stack b by 1. 
	RRR
}	t_move_types;

#endif
