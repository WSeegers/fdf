/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:28:26 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/06 14:04:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_window.h"
#include "s_line_list.h"
#include "point_vector.h" 
#include "gfxwtc.h"

#include <stdio.h>

static void	c_transform(t_point *p, t_vec3 *v, t_window *win)
{
	double zscale;
	
	if (v->z > 1)
	{
		zscale = 1 / (v->z);
		p->x = ((v->x) * zscale + 1.0) * win->xscale;
		p->y = (-(v->y) * zscale + 1.0) * win->yscale;
	}
	else
	{
		p->x = -1;
		p->y = -1;
	}
}

void	draw(t_window *win, t_line_list *llist)
{
	size_t i;
	t_point p1;
	t_point p2;

	i = 0;
	while (i < llist->indicies->total)
	{
		c_transform(&p1, LLIST_GET(llist, i++), win);
		c_transform(&p2, LLIST_GET(llist, i++), win);
		if (p1.x == -1 || p2.x == -1)
			continue;
		draw_line(win, &p1, &p2, 0xffffff);
	}
}
