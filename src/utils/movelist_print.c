/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movelist_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:40:14 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/27 17:25:33 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static char	(*get_move_names(void))[11][6]
{
	static char	move_names[11][6];
	static char	initialized;

	if (!initialized)
	{
		ft_strlcpy(move_names[0], "sa\0", 5);
		ft_strlcpy(move_names[1], "sb\0", 5);
		ft_strlcpy(move_names[2], "ss\0", 5);
		ft_strlcpy(move_names[3], "pa\0", 5);
		ft_strlcpy(move_names[4], "pb\0", 5);
		ft_strlcpy(move_names[5], "ra\0", 5);
		ft_strlcpy(move_names[6], "rb\0", 5);
		ft_strlcpy(move_names[7], "rr\0", 5);
		ft_strlcpy(move_names[8], "rra\0", 6);
		ft_strlcpy(move_names[9], "rrb\0", 6);
		ft_strlcpy(move_names[10], "rrr\0", 6);
		initialized = 1;
	}
	return (&move_names);
}

static t_move	*get_movelist(void)
{
	static t_move	movelist[11];
	static char		initialized;

	if (initialized)
		return (movelist);
	movelist[0] = sa;
	movelist[1] = sb;
	movelist[2] = ss;
	movelist[3] = pa;
	movelist[4] = pb;
	movelist[5] = ra;
	movelist[6] = rb;
	movelist[7] = rr;
	movelist[8] = rra;
	movelist[9] = rrb;
	movelist[10] = rrr;
	initialized = 1;
	return (movelist);
}

static int	get_move_index(t_move move)
{
	int	counter;

	counter = 0;
	while (counter < 11)
	{
		if (move == get_movelist()[counter])
			return (counter);
		counter++;
	}
	return (-1);
}
void	print_movelist(t_list *movelist)
{
	char	(*move_names)[11][6];
	int		index;

	move_names = get_move_names();
	while (movelist != NULL)
	{
		index = get_move_index((t_move) movelist->content);
		ft_printf("%s\n", (*move_names)[index]);
		movelist = movelist->next;
	}
}
