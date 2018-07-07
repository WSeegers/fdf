/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_line_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:17:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 09:54:36 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LINE_LIST_H
# define S_LINE_LIST_H

# include <stdbool.h>
# include "point_vector.h"
# include "s_vector.h"
# include "s_window.h"

typedef struct	s_line_list
{
	t_vector *verticies;
	t_vector *indicies;
}				t_line_list;

# define LLIST_VGET(llist, i) (VECTOR_GET(llist->verticies, t_vec3*, i))
# define LLIST_IGET(llist, i) (VECTOR_GET(llist->indicies, size_t, i))
# define LLIST_GET(llist, i) (LLIST_VGET(llist, LLIST_IGET(llist, i)))

# define LLIST_ADD_VERT(llist, v3)	(vector_add(llist->verticies, v3))

t_line_list		*line_list_create(void);
void			llist_add_vert(t_line_list *llist, t_vec3 *v);
void			llist_add_line(t_line_list *llist, size_t i1, size_t i2);
void			draw(t_window *win, t_line_list *llist);

#endif
