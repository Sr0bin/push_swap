/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:29:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/29 19:55:10 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_populate(int argc, char **argv, t_context *context)
{
	int	*array;
	int	counter;

	if (argc <= 1)
		error_handling(INIT_ERROR, &context);
	array = NULL;
	context->array = array_init(argv[1]);
	counter = 2;
	while (counter < argc)
	{
		array = array_init(argv[counter]);
		context->array = array_join(&(context->array), &array);
		counter++;
	}
}

void	array_valid(const int *array)
{
	int	i;
	int	j;

	i = 1;
	while (i < array[0])
	{
		j = i + 1;
		while (j <= array[0])
		{
			if (array[i] == array[j])
				error_handling(DUPLICATE_NBR, NULL);
			j++;
		}
		i++;
	}
}

t_stack	*stack_populate(int *array)
{
	t_stack	*stack;
	t_node	*temp;
	int		counter;

	counter = 1;
	if (array[0] < 1)
		return (NULL);
	temp = node_init(array[array[0] - counter + 1]);
	if (temp == NULL)
		error_handling(MEM_ERROR, NULL);
	stack = stack_init(temp);
	while (counter < array[0])
	{
		temp = node_init(array[(array[0] - ++counter) + 1]);
		if (temp == NULL)
		{
			free_stack(&stack);
			error_handling(MEM_ERROR, NULL);
		}
		stack_add_node(stack, temp);
	}
	return (stack);
}
