/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:44:47 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/12 16:46:25 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include "string.h"

size_t	array_length(void **array)
{
	size_t size;

	size = 0;
	if (array == NULL)
		return (0);
	while (array[size] != NULL)
		size++;
	return (size);
}

void	free_array(void ***array)
{
	size_t	counter;

	counter = 0;
	if (array == NULL || *array == NULL)
		return ;
	while ((*array)[counter]!= NULL)
		free((*array)[counter++]);
	free((void *) *array);
	*array = NULL;
}

int	*array_init(char *str)
{
	int	*array;
	size_t	len;
	char	**numbers;
	long long	temp;

	numbers = ft_split(str, ' ');	
	if (numbers == NULL)
		error_handling(MEM_ERROR, NULL);
	len = array_length((void **) numbers);
	array = ft_calloc(sizeof(*array), len + 1);
	if (array == NULL)
	{
		free_array((void ***) &numbers);
		error_handling(MEM_ERROR, NULL);
	}
	array[0] = (int) len;
	while (len != 0)
	{
		temp = ft_atol(numbers[len - 1]);
		if (temp >= INT_MAX || temp <= INT_MIN || !ft_validnumber(numbers[len - 1]))
		{
			free_array((void ***) &numbers);
			free(array);
			error_handling(ARG_SIZE_INT, NULL);
		}
		array[len--] = (int) temp;
	}
	free_array((void ***) &numbers);
	return(array);
}

int	*array_join(int	**array1, int	**array2)
{
	int	i;
	int	*new_array;

	i = 1;
	new_array = ft_calloc(sizeof(**array1), (size_t) ((*array1)[0] + (*array2)[0] + +1));
	if (new_array == NULL)
	{
		free(*array2);
		error_handling(MEM_ERROR, NULL);
	}
	new_array[0] = (*array1)[0] + (*array2)[0];
	while (i < (*array1)[0] + 1)
	{
		new_array[i] = (*array1)[i];
		i++;
	}
	while (i < (*array1)[0] + (*array2)[0] + 1)
	{
		new_array[i] = (*array2)[i - (*array1)[0]];
		i++;
	}
	free(*array1);
	array1 = NULL;
	free(*array2);
	array2 = NULL;
	return(new_array);
}
