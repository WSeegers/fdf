/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:09:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 18:12:21 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_line_list.h"
#include "f_memory.h"

t_line_list	*line_list_create(void)
{
	t_line_list *llist;

	llist = (t_line_list*)f_memalloc(sizeof(*llist));
	llist->verticies = vector_create();
	llist->indicies = vector_create();
	return (llist);
}
