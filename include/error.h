/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 02:58:50 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/28 03:15:33 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERROR_H
# define ERROR_H
# include "libft.h"
# include "struct.h"

//------------------------------------------------- 
//					Error
//------------------------------------------------- 
typedef enum e_error_types
{
	SET_CONTEXT, // Used to set context.
	MEM_ERROR, // When a malloc fails.
	INIT_ERROR,
	ARG_DUP, // Duplicates in arguments
	ARG_NAN, //Arguments are not valid numbers
	ARG_SIZE_INT, // Arguments are too big
	UNEXPECTED_NULL
} t_error_types;

void	error_handling(size_t error_code, t_context **context);

//------------------------------------------------- 
//					Debug
//------------------------------------------------- 
t_stack	*fake_stack(size_t n);
void	print_stack(const t_stack *stack);
t_context	*fake_context(size_t a, size_t b);
void	print_context(t_context *context);
#endif
