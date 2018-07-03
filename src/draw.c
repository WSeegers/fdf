/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:28:26 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 13:48:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_window.h"
#include "s_line_list.h"
#include "point_vector.h" 
#include "gfxwtc.h"

#include <stdio.h>

static void	c_transform(t_point *p, t_vec3 *v, t_window *win)
{
	double zscale;
	
	zscale = 1 / (v->z);

	printf("(%f, %f, %f) ->", v->x, v->y, v->z);
	printf("(%f, %f, %f) ->", ((v->x) * zscale + 1.0) * win->xscale,
							((-(v->y)) * zscale + 1.0) * win->yscale, zscale);
	p->x = ((v->x) * zscale + 1.0) * win->xscale;
	p->y = ((-(v->y)) * zscale + 1.0) * win->yscale;
	printf("(%d, %d)\n", p->x, p->y);
}

void	draw(t_window *win, t_line_list *llist)
{
	size_t i;
	t_point p1;
	t_point p2;

	i = 0;
	while (i < llist->indicies->total)
	{
		//printf("ind: %lu, %lu\n", LLIST_IGET(llist, i), LLIST_IGET(llist, i + 1));
		c_transform(&p1, LLIST_GET(llist, i++), win);
		c_transform(&p2, LLIST_GET(llist, i++), win);
		draw_line(win, &p1, &p2, 0xffffff);
	}
}
