/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:58:26 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/15 18:39:32 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "error.h"
#include "list.h"
#include "movelist.h"
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
		free(stack_b);
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
				func_moves[SA](context);
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
 void	parsing_test(void)
{
	int	*array1;
	int	*array2;
	char *test;

	test = ft_strdup("");
	array1 = array_init(test);
	array2 = array_init(test);
	array1 = array_join(&array1, &array2);
	print_array(array1);
	free(array1);
	free(test);
}


void	movelist_test(void)
{
	t_list	*movelist;

	movelist = ft_lstnew(sa);
	movelist_add_n(&movelist, rrr, 1);
	print_movelist(movelist);
	free_movelist(&movelist);
}
