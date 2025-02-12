/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:00:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/12 17:52:02 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

void	test_gnl(int fd)
{
	char	*line;
	size_t counter;

	fd = open("/home/rorollin/francinette/tests/get_next_line/fsoares/one_line_no_nl.txt", O_RDONLY);
	// fd = 42;
	printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
	line = get_next_line(fd);
	counter = 0;
	printf("Line number %zu\n Line : %s\n", counter, line);
	while (line != NULL)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
		printf("Line number %zu\n Line : %s", counter, line);
	}
}


int	main(void)
{
	test_gnl(1);
	return (0);
}
