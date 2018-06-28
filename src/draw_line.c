/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:27:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 18:52:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "gfxwtc.h"
#include "f_memory.h"
#include "f_math.h"

static void	draw_vert(t_win win, t_point p1, t_point p2, t_colour col)
{
	int start;
	int end;
	t_mlx mlx;

	mlx = get_mlx();
	start = f_min(p1.y, p2.y) - 1;
	end = f_max(p1.y, p2.y);
	while (++start < end)
		mlx_pixel_put(mlx, win, p1.x, start, col);
}

static void	draw_on_x(t_win win, t_point p1, t_point p2, t_colour col)
{
	double y;
	double m;
	t_mlx mlx;

	mlx = get_mlx();
	m = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	y = (double)p1.y;
	while (p1.x	< p2.x)
	{
		mlx_pixel_put(mlx, win, p1.x++, y, col);
		y += m;
	}
}

static void	draw_on_y(t_win win, t_point p1, t_point p2, t_colour col)
{
	double x;
	double m;
	t_mlx mlx;

	mlx = get_mlx();
	m = (double)(p2.x - p1.x) / (double)(p2.y - p1.y);
	x = (double)p1.x;
	while (p1.y	< p2.y)
	{
		mlx_pixel_put(mlx, win, x, p1.y++, col);
		x += m;
	}
}

#include <stdio.h>

void	draw_line(t_window *win, t_point *p1, t_point *p2, t_colour col)
{
	int	dx;
	int dy;
	double m;

	printf("LINE: (%d, %d) -> (%d, %d)\n", p1->x, p1->y, p2->x, p2->y);
	
	if (p1->x == p2->x)
	{
		if (p1->y == p2->y)
			mlx_pixel_put(get_mlx(), win->win, p1->x, p1->y, col);
		else
			draw_vert(win->win, *p1, *p2, col);
		return ;
	}
	if (p1->x > p2->x)
		f_swapptr((void**)&p1, (void**)&p2);
	m = (double)(dy = p2->y - p1->y) / (double)(dx = p2->x - p1->x);
	if (fabs(m) <= 1)
			draw_on_x(win->win, *p1, *p2, col);
	else
	{
		if (p1->y > p2->y)
			f_swapptr((void**)&p1, (void**)&p2);
		draw_on_y(win->win, *p1, *p2, col);
	}
}

