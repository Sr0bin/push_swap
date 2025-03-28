/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movelist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:40:41 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 08:49:34 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	movelist_free(void *p)
{
	(void) p;
}

void	free_movelist(t_list **movelist)
{
	ft_lstclear(movelist, movelist_free);
	*movelist = NULL;
	movelist = NULL;
}

t_list	*movelist_init(t_move move)
{
	t_list	*movelist;

	movelist = ft_lstnew(move);
	if (movelist == NULL)
		error_handling(MEM_ERROR, NULL);
	return (movelist);
}

void	movelist_add_n(t_list **movelist, t_move move, size_t n)
{
	size_t	counter;
	t_list	*node;

	counter = 0;
	node = NULL;
	while (counter < n)
	{
		node = ft_lstnew(move);
		if (node == NULL)
			error_handling(MEM_ERROR, NULL);
		ft_lstadd_back(movelist, node);
		counter++;
	}
}

t_list	*mvlist_replace_n(t_list **movelist, t_move move, size_t n, size_t end)
{
	t_list	*current;
	t_list	*new;
	t_list	*end_list;
	t_list	*old;
	size_t	counter;

	if (movelist == NULL || *movelist == NULL || n == 0)
		return (NULL);
	current = *movelist;
	counter = 0;
	end_list = ft_lstlast(*movelist);
	while (current != NULL && counter < end)
	{
		if (counter == end - 1)
		{
			end_list = current->next;
			current->next = NULL;
			break ;
		}
		current = current->next;
		counter++;
	}
	old = *movelist;
	new = movelist_init(move);
	movelist_add_n(&new, move, n - 1);
	ft_lstadd_back(&new, end_list);
	*movelist = new;
	if (old != NULL)
		free_movelist(&old);
	return (new);
}
