/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 00:34:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 01:13:10 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "s_cube.h"


void	draw_cube(t_window *win, t_cube *cube)
{
	t_vec3 **v3;

	v3 = cube->vector;
	//draw_line(win, &NEW_POINT(100, 100), &NEW_POINT(400, 400), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[0]), VEC3_TO_POINT(v3[1]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[1]), VEC3_TO_POINT(v3[2]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[2]), VEC3_TO_POINT(v3[3]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[3]), VEC3_TO_POINT(v3[0]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[4]), VEC3_TO_POINT(v3[5]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[5]), VEC3_TO_POINT(v3[6]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[6]), VEC3_TO_POINT(v3[7]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[7]), VEC3_TO_POINT(v3[4]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[0]), VEC3_TO_POINT(v3[4]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[1]), VEC3_TO_POINT(v3[5]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[2]), VEC3_TO_POINT(v3[6]), 0xffffff);
	draw_line(win, VEC3_TO_POINT(v3[3]), VEC3_TO_POINT(v3[7]), 0xffffff);
}
