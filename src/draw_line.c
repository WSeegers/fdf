/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:27:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/06 13:56:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "gfxwtc.h"
#include "f_memory.h"
#include "f_math.h"

#include <stdio.h>

static void	draw_vert(t_window *win, t_point p1, t_point p2, t_colour col)
{
	int start;
	int end;
	t_mlx mlx;

	mlx = get_mlx();
	start = f_max((f_min(p1.y, p2.y) - 1), 0);
	end = f_min(f_max(p1.y, p2.y), win->height);
	while (++start < end)
		mlx_pixel_put(mlx, win->win, p1.x, start, col);
}

static void	draw_on_x(t_window *win, t_point p1, t_point p2, t_colour col)
{
	t_mlx mlx;
	int y;
	int de;
	int e;
	int dx;

	mlx = get_mlx();
	y = p1.y;
	dx = p2.x - p1.x;
	de = f_abs(p2.y - p1.y) * 2;
	e = 0;
	p1.x = f_max(p1.x, 0);
	p2.x = f_min(p2.x, win->width);
	while (p1.x	< p2.x)
	{
		mlx_pixel_put(mlx, win->win, p1.x++, y, col);
		e += de;
		if (e > dx)
		{
			y += (p2.y > p1.y) ? 1 : -1;	
			e -= dx * 2;
		}
	}
}

static void	draw_on_y(t_window *win, t_point p1, t_point p2, t_colour col)
{
	t_mlx mlx;
	int x;
	int de;
	int e;
	int dy;

	mlx = get_mlx();
	x = p1.x;
	dy = p2.y - p1.y;
	de = f_abs(p2.x - p1.x) * 2;
	e = 0;
	p1.y = f_max(p1.y, 0);
	p2.y = f_min(p2.y, win->height);
	while (p1.y	< p2.y)
	{
		mlx_pixel_put(mlx, win->win, x, p1.y++, col);
		e += de;
		if (e > dy)
		{
			x += (p2.x > p1.x) ? 1 : -1;	
			e -= dy * 2;
		}
	}
}


void	draw_line(t_window *win, t_point *p1, t_point *p2, t_colour col)
{
	int	dx;
	int dy;
	double m;

	//printf("LINE: (%d, %d) -> (%d, %d)\n", p1->x, p1->y, p2->x, p2->y);
	
	if (p1->x == p2->x)
	{
		if (p1->y == p2->y)
			mlx_pixel_put(get_mlx(), win->win, p1->x, p1->y, col);
		else
			draw_vert(win, *p1, *p2, col);
		return ;
	}
	if (p1->x > p2->x)
		f_swapptr((void**)&p1, (void**)&p2);
	m = (double)(dy = p2->y - p1->y) / (double)(dx = p2->x - p1->x);
	if (fabs(m) <= 1)
			draw_on_x(win, *p1, *p2, col);
	else
	{
		if (p1->y > p2->y)
			f_swapptr((void**)&p1, (void**)&p2);
		draw_on_y(win, *p1, *p2, col);
	}
}

