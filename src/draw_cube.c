/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 00:34:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 15:34:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "s_cube.h"


void	draw_cube(t_window *win, t_cube *cube)
{
	t_vec3 **v3;

	v3 = cube->vector;
	draw_line(win, VEC_TO_POINT(v3[0]), VEC_TO_POINT(v3[1]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[1]), VEC_TO_POINT(v3[2]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[2]), VEC_TO_POINT(v3[3]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[3]), VEC_TO_POINT(v3[0]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[4]), VEC_TO_POINT(v3[5]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[5]), VEC_TO_POINT(v3[6]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[6]), VEC_TO_POINT(v3[7]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[7]), VEC_TO_POINT(v3[4]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[0]), VEC_TO_POINT(v3[4]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[1]), VEC_TO_POINT(v3[5]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[2]), VEC_TO_POINT(v3[6]), 0xffffff);
	draw_line(win, VEC_TO_POINT(v3[3]), VEC_TO_POINT(v3[7]), 0xffffff);
}
