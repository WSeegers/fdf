/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 01:13:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfxwtc.h"
#include <stdio.h>

int main(void)
{
	t_window *win;
	t_mlx mlx;
	
	mlx = get_mlx();
	win = create_window(600, 600, "WINDOW!!");

	t_cube *cube = create_cube(300);
	for(int i = 0; i < 8; i++)
	{
		cube->vector[i]->x += 300;
		cube->vector[i]->y += 300;
		printf("[%d](%.0f, %.0f)\n", i, 
								(cube->vector)[i]->x, (cube->vector)[i]->y);
		fflush(stdout);
	}
	draw_cube(win, cube);

	mlx_loop(mlx);
	return (0);
}
