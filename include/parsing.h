/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:08:55 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/28 11:48:42 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "libft.h"
# include "struct.h"

int		*array_init(char *str);
int		*array_join(int	**array1, int	**array2);
void	array_populate(int argc, char **argv, t_context *context);
void	array_valid(const int *array);
t_stack	*stack_populate(int *array);
#endif
