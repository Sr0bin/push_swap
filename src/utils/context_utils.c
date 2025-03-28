/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:29:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 12:33:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_context	*context_init(int argc, char **argv)
{
	t_context	*context;

	context = ft_calloc(1, sizeof(t_context));
	if (context == NULL)
		error_handling(MEM_ERROR, &context);
	error_handling(SET_CONTEXT, &context);
	array_populate(argc, argv, context);
	array_valid(context->array);
	context->stack_a = stack_populate(context->array);
	context->stack_b = stack_init(NULL);
	context->end_mvlist = NULL;
	return (context);
}

void	apply_movelist(t_context *context, t_list *movelist)
{
	t_list	*current_move;

	current_move = movelist;
	while (current_move != NULL)
	{
		((t_move)current_move->content)(context);
		current_move = current_move->next;
	}
}

void	append_movelist(t_context *context, t_list *movelist)
{
	t_list	*current_node;

	if (context->end_mvlist == NULL)
	{
		context->end_mvlist = movelist;
		return ;
	}
	current_node = context->end_mvlist;
	while (current_node != NULL)
	{
		if (current_node == movelist)
			return ;
		current_node = current_node->next;
	}
	ft_lstadd_back(&context->end_mvlist, movelist);
}

void	apply_apnd_mvlist(t_context *context, t_list **movelist)
{
	apply_movelist(context, *movelist);
	append_movelist(context, *movelist);
	*movelist = NULL;
}

void	free_context(t_context **context)
{
	if (context == NULL || *context == NULL)
		return ;
	free_stack(&(*context)->stack_a);
	free_stack(&(*context)->stack_b);
	free((*context)->array);
	free_movelist(&(*context)->end_mvlist);
	free(*context);
	*context = NULL;
}
