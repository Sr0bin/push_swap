/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movelist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:40:41 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/13 16:13:20 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_move_names(void)
{
	static char	move_names[11][5];
	static char	initialized;
	
	if (!initialized)
	{
		ft_strlcpy(move_names[0], "(sa)", 5);
        ft_strlcpy(move_names[1], "(sb)", 5);
        ft_strlcpy(move_names[2], "(ss)", 5);
        ft_strlcpy(move_names[3], "(pa)", 5);
        ft_strlcpy(move_names[4], "(pb)", 5);
        ft_strlcpy(move_names[5], "(ra)", 5);
        ft_strlcpy(move_names[6], "(rb)", 5);
        ft_strlcpy(move_names[7], "(rr)", 5);
        ft_strlcpy(move_names[8], "(rra)", 5);
        ft_strlcpy(move_names[9], "(rrb)", 5);
        ft_strlcpy(move_names[10], "(rrr)", 5);
        initialized = 1;
	}
	return (char **) move_names;

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

void	print_movelist(t_move *movelist)
{
	size_t	counter;
	char **move_names;

	counter = 0;
	move_names = get_move_names();
	while (movelist[counter] != NULL)
	{
		ft_printf("%s\n", move_names[get_move_index(movelist[counter])]);	
		counter++;
	}
}
