/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:08:55 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/28 03:58:08 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "libft.h"
int	*array_create(char *str);
void	free_array(void ***array);
size_t	array_length(void **array);
int	*array_join(int	**array1, int	**array2);
#endif
