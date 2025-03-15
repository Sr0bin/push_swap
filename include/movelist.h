/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movelist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:15:43 by rorollin          #+#    #+#             */
/*   Updated: 2025/03/15 18:53:35 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVELIST_H
# define MOVELIST_H
# include "list.h"
# include "struct.h"

void	print_movelist(t_list *movelist);
void	movelist_add_n(t_list **movelist, t_move move, size_t n);
void	free_movelist(t_list **movelist);
t_list	*movelist_init(t_move move);
#endif
