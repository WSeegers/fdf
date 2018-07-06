/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_add_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:18:14 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/06 13:10:17 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_line_list.h"
#include "point_vector.h" 
#include "f_memory.h"

void		llist_add_line(t_line_list *llist, size_t i1, size_t i2)
{
	size_t i;

	i = 0;
	while (i < llist->indicies->total)
	{
		if ((unsigned long)llist->indicies->data[i] == i1 &&
				(unsigned long)llist->indicies->data[i + 1] == i2)
			return ;
		if ((unsigned long)llist->indicies->data[i + 1] == i1 &&
				(unsigned long)llist->indicies->data[i] == i2)
			return ;
		i += 2;
	}
	vector_add(llist->indicies, (void*)i1);
	vector_add(llist->indicies, (void*)i2);
}
