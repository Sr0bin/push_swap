/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:31:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/26 20:20:45 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_test(void)
{
	
	t_stack *stack_a;
	t_stack *stack_b;
	size_t	counter;
	size_t	i;
	// size_t	j;

	counter = 0;
	i = 0;
	// j = 0;
	while(counter < 2)
	{
		stack_a = fake_stack(counter + 10);
		stack_b = fake_stack(counter);
		// print_stack(stack_a);
		// print_stack(stack_b);
		while(i++ <= counter + 1)
			push_stack(stack_b, stack_a);
		// free(stack_remove_node(stack_a));
		// rotate_stack(stack);
		// reverse_rotate_stack(stack);
		// print_stack(stack_a);
		print_stack(stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
		counter++;
	}
}
void	context_test(void)
{
	t_context	*context;
	size_t	counter;
	size_t	i;
	size_t	j;

	const t_move func_moves[11] = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
	// const char *func_moves_names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < i)
		{	
			counter = 0;
			while (counter < 11)
			{
				context = fake_context(i, j);
				func_moves[counter](context);
				// printf("\n Move is : %s\n", func_moves_names[counter]);
				// print_context(context);
				free_context(&context);
				counter++;
			}
			j++;
		}
		i++;
	}
	context = NULL;
}

void	realloc_test()
{
	char	*str;
	size_t	counter;

	str = ft_strdup("test");
	counter = 0;
	str = ft_realloc(str, 8);
	while(counter < 8)
		printf("%c", str[counter++]);
	free(str);

}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	// stack_test();
	context_test();
	// realloc_test();
	return (EXIT_SUCCESS);
}
