/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_add_vert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:16:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 10:12:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_line_list.h"
#include "point_vector.h"

void	llist_add_vert(t_line_list *llist, t_vec3 *v)
{
	vector_add(llist->verticies, v);
}
