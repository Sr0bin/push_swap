/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:38:49 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/21 17:03:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(size_t error_code, t_context **context)
{
	static	t_context *saved_context;

	if (error_code == 0)
	{
		saved_context = *context;
		return ;
	}
	if (error_code == MEM_ERROR)
	{
		free_context(&saved_context);
		exit(EXIT_FAILURE);
	}
}
