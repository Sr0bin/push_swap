/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:14:11 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/21 16:53:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

t_node	*node_init(int value);
void	push_node(t_node *head, t_node *new);
void	pop_node(t_node *node);
void	free_node(t_node **node);

//------------------------------------------------- 
//					Stack
//------------------------------------------------- 

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;

t_stack	*stack_init(t_node *node);
void	stack_add_node(t_stack *stack, t_node *node);
t_node	*stack_remove_node(t_stack *stack);
void	free_stack(t_stack **stack);
void	swap_top_stack(t_stack *n);
void	push_stack(t_stack *giver, t_stack *receiver);
void	rotate_stack(t_stack *n);
void	reverse_rotate_stack(t_stack *n);

//------------------------------------------------- 
//					Context
//------------------------------------------------- 

typedef struct s_context
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_context;

t_context	*context_init(t_stack *stack_a, t_stack *stack_b);
void		free_context(t_context **context);

//------------------------------------------------- 
//				Moves for context
//------------------------------------------------- 
typedef void	(*t_move)(t_context *context);

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

//------------------------------------------------- 
//					Error
//------------------------------------------------- 
typedef enum e_error_types
{
	MEM_ERROR = 1, // When a malloc fails.
	ARG_DUP, // Duplicates in arguments
	ARG_NAN, //Arguments are not valid numbers
	ARG_SIZE_INT // Arguments are too big
} t_error_types;

//------------------------------------------------- 
//					Debug
//------------------------------------------------- 
t_stack	*fake_stack(size_t n);
void	print_stack(const t_stack *stack);
t_context	*fake_context(size_t a, size_t b);
void	print_context(t_context *context);
#endif
