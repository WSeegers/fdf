/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 20:41:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfxwtc.h"
#include <stdio.h>
#include <unistd.h>

static t_line_list *cube_create(void)
{
	t_line_list *llist = line_list_create();

	llist_add_vert(llist, vec3_create(-0.5, -0.5, -0.5));
	llist_add_vert(llist, vec3_create(0.5, -0.5, -0.5));
	llist_add_vert(llist, vec3_create(0.5, 0.5, -0.5));
	llist_add_vert(llist, vec3_create(-0.5, 0.5, -0.5));

	llist_add_vert(llist, vec3_create(-0.5, -0.5, 0.5));
	llist_add_vert(llist, vec3_create(0.5, -0.5, 0.5));
	llist_add_vert(llist, vec3_create(0.5, 0.5, 0.5));
	llist_add_vert(llist, vec3_create(-0.5, 0.5, 0.5));

	llist_add_line(llist, 0, 1);
	llist_add_line(llist, 1, 2);
	llist_add_line(llist, 2, 3);
	llist_add_line(llist, 3, 0);

	llist_add_line(llist, 4, 5);
	llist_add_line(llist, 5, 6);
	llist_add_line(llist, 6, 7);
	llist_add_line(llist, 7, 4);

	llist_add_line(llist, 0, 4);
	llist_add_line(llist, 1, 5);
	llist_add_line(llist, 2, 6);
	llist_add_line(llist, 3, 7);

	return (llist);
}

typedef struct	s_param
{
	t_line_list *cube;
	t_mat4		*roty;
	t_window	*win;
}				t_param;

int	f_roty(void *param)
{
	t_param *p;
	size_t i;

	p = (t_param*)param;
	i = 0;
	while (i < p->cube->verticies->total)
		vec3_transf(LLIST_VGET(p->cube, i++), p->roty);

	mlx_clear_window(get_mlx(), p->win->win);
	draw(p->win, p->cube);
	usleep(50000);
	return (0);
}

int main(void)
{
	t_window *win;
	t_mlx mlx;
	
	mlx = get_mlx();
	win = create_window(800, 800, "WINDOW!!");

	t_line_list *cube = cube_create();

	t_mat4 roty;
	rotate_y(&roty, M_PI * 0.01);

	t_param param;
	param.cube = cube;
	param.roty = &roty;
	param.win = win;
	
	fflush(stdout);

	mlx_loop_hook(get_mlx(), f_roty, &param);
	mlx_loop(mlx);
	return (0);
}
