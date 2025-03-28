/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:47:49 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/27 17:25:04 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_target	target_init(void)
{
	t_target	target;

	target.target_node = NULL;
	target.movelist = NULL;
	target.cost = 0;
	return (target);
}

void	free_target(t_target *target)
{
	if (target->movelist != NULL)
		free_movelist(&(target->movelist));
}
