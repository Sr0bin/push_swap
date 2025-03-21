/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:47:49 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/21 16:51:19 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_target	target_init(void)
{
	t_target target;

	target.target_node = NULL;
	target.movelist = NULL;
	target.cost = 0;
	return (target);
}

void	free_target(t_target *target)
{
	free_movelist(&(target->movelist));
	*target = target_init();
}
