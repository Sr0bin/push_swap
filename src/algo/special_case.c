/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:12:42 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 12:14:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movelist_add_sa_ra(t_list **movelist)
{
	movelist_add_n(movelist, sa, 1);
	movelist_add_n(movelist, ra, 1);
}
