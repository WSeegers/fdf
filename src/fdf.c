/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 19:10:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfxwtc.h"
#include "f_memory.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*static t_line_list *cube_create(void)
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
	t_window	*win;
	t_vec3		rot;
}				t_param;

int	loop(void *param)
{
	t_param *p;
	t_line_list *block1;
	//t_line_list *block2;
	//t_line_list *block3;
	//t_line_list *block4;

	p = (t_param*)param;

	block1 = transform(p->cube, (t_vec3){1, 1, 1}, 
								(t_vec3){p->rot.x * M_PI, p->rot.y * M_PI, p->rot.z * M_PI}, 
								(t_vec3){0, 0, 2});
	//block2 = transform(p->cube, (t_vec3){1, 1, 1}, (t_vec3){0 , 0, r * M_PI}, (t_vec3){0, 2, 2});
	//block3 = transform(p->cube, (t_vec3){1, 1, 1}, (t_vec3){0 , r * M_PI, 0}, (t_vec3){0, 0, 2});
	//block4 = transform(p->cube, (t_vec3){1, 1, 1}, (t_vec3){r * M_PI, 0, 0}, (t_vec3){0, -2, 2});
	

	mlx_clear_window(get_mlx(), p->win->win);
	draw(p->win, block1);
	//draw(p->win, block2);
	//draw(p->win, block3);
	//draw(p->win, block4);
	//draw(p->win, p->cube);
	usleep(50000);
	f_memdel((void**)&block1);
	//f_memdel((void**)&block2);
	//f_memdel((void**)&block3);
	//f_memdel((void**)&block4);
	return (0);
}

# define ROT_SPEED 0.05

int key_hook(int keycode,void *param)
{
	t_param *p;


	p = (t_param*)param;

	if (keycode == 0) //A
		p->rot.y = fmod((p->rot.y += ROT_SPEED), 2);
	else if (keycode == 2) //D
		p->rot.y = fmod((p->rot.y -= ROT_SPEED), 2);
	else if (keycode == 13) //W
		p->rot.x = fmod((p->rot.x += ROT_SPEED), 2);
	else if (keycode == 1) // S
		p->rot.x = fmod((p->rot.x -= ROT_SPEED), 2);
	else if (keycode == 12) //Q
		p->rot.z = fmod((p->rot.z += ROT_SPEED), 2);
	else if (keycode == 14) // E
		p->rot.z = fmod((p->rot.z -= ROT_SPEED), 2);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	printf("keypress -> %d\n (%d, %d)", button, x, y);
	return (0);
}*/


int main(void)
{
	t_window *win;
	t_mlx mlx;
	
	mlx = get_mlx();
	win = create_window(800, 800, "WINDOW!!");

	//t_line_list *cube = cube_create();
	t_line_list *map = parse_map();

	//printf("Vericies: %lu\n", map->verticies->total);
	//printf("Lines: %lu\n", map->indicies->total);
	map = transform(map, (t_vec3){0.5, 0.5, 0.5}, 
								(t_vec3){M_PI * -0.10, M_PI * -0.25, 0}, 
								(t_vec3){-5, 0, 10});

	fflush(stdout);
	draw(win, map);

/*	t_param param;
	param.cube = cube;
	param.win = win;
	param.rot.x = 0;
	param.rot.y = 0;
	param.rot.z = 0;
	
	mlx_mouse_hook(win->win, mouse_hook, &param);
	mlx_key_hook(win->win, key_hook, &param);
	mlx_loop_hook(get_mlx(), loop, &param);
*/	mlx_loop(mlx);
	return (0);
}
