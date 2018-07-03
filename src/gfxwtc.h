/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfxwtc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:37:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 12:57:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFXWTC_H
# define GFXWTC_H

#include <math.h>
#include "point_vector.h"
#include "s_window.h"
#include "s_line_list.h"
#include "s_gfx_matrix.h"
#include "colours.h"

#include "s_cube.h"

typedef void*		t_mlx;

t_mlx		get_mlx(void);
t_line_list	*parse_map(void);
void		draw_line(t_window *win, t_point *p1, t_point *p2, t_colour col);
t_line_list *transform(t_line_list *llist, t_vec3 scale,
										t_vec3 rot, t_vec3 transl);
void	rotate_y(t_mat4 *m4, double rad);

#endif
