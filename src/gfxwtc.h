/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfxwtc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:37:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 00:54:06 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFXWTC_H
# define GFXWTC_H

#include "s_vector.h"
#include "s_window.h"
#include "colours.h"

#include "s_cube.h"

typedef void*		t_mlx;

t_mlx	get_mlx(void);
void	draw_line(t_window *win, t_point *p1, t_point *p2, t_colour col);

#endif
