/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:29:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/06 13:34:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfxwtc.h"
#include "f_memory.h"

t_window *create_window(int height, int width, char *title)
{
	t_window *win;

	win = (t_window*)f_memalloc(sizeof(*win));
	if (!title)
		win->win = mlx_new_window(get_mlx(), width, height, "(no title)");
	else
		win->win = mlx_new_window(get_mlx(), width, height, title);
	win->height = height;
	win->width = width;
	win->xscale = width / 2.0;
	win->yscale = height / 2.0;
	return (win);
}
