/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movelist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:40:41 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/15 18:53:55 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	movelist_free(void *p)
{
	(void) p;
}

void	free_movelist(t_list **movelist)
{
	ft_lstclear(&(*movelist), movelist_free);
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
		ft_lstadd_back(&(*movelist), node);
		counter ++;
	}
}
