/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:29:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/21 16:53:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_join(int	**array1, int	**array2)
{
	int	i;
	int	*new_array;

	i = 1;
	new_array = ft_calloc(sizeof(typeof(**array1)), *array1[0] + *array2[0] + 1);
	if (new_array == NULL)
		return (NULL);
	new_array[0] = *array1[0] + *array2[0];
	while (i < *array1[0] + 1)
	{
		new_array[i] = *array1[i];
		i++;
	}
	while (i < *array1[0] + *array2[0] + 1)
	{
		new_array[i] = *array2[i];
		i++;
	}
	free(*array1);
	free(*array2);
	return(new_array);
}

int	*array_create(char *str)
{
	int	*array;
	char	**numbers;

	numbers = ft_split(str, ' ');	
	if (numbers == NULL)

		ft_atoi(str);

	return(array);
}
int	*array_init(int argc, char **argv)
{
	int	*array;

	
	return (array);
}
