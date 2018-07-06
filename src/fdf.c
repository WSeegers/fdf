/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/06 14:02:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfxwtc.h"
#include "f_memory.h"
#include <stdlib.h>

static int	draw_loop(void *param)
{
	t_param *p;
	t_line_list *block1;

	p = (t_param*)param;

	p->rot.y = fmod((p->rot.y = p->rot.y + p->drot.y), 2);
	block1 = transform(p->map, p->scale, 
								(t_vec3){p->rot.x * M_PI, p->rot.y * M_PI, p->rot.z * M_PI}, 
								p->transl);
	mlx_clear_window(get_mlx(), p->win->win);
	draw(p->win, block1);
	f_memdel((void**)&block1);
	return (0);
}


#include <stdio.h>

int key_hook(int keycode,void *param)
{
	t_param *p;

	printf("keypress -> %d\n", keycode);
	p = (t_param*)param;

	if (keycode == 0) //A
		p->drot.y += ROT_SPEED;
	else if (keycode == 2) //D
		p->drot.y -= ROT_SPEED;
	else if (keycode == 13) //W
		p->rot.x = fmod((p->rot.x += ROT_SPEED), 2);
	else if (keycode == 1) // S
		p->rot.x = fmod((p->rot.x -= ROT_SPEED), 2);
	else if (keycode == 12) //Q
		p->rot.z = fmod((p->rot.z += ROT_SPEED), 2);
	else if (keycode == 14) // E
		p->rot.z = fmod((p->rot.z -= ROT_SPEED), 2);
	else if (keycode == 49) // Space
	{
		p->drot.x = 0;
		p->drot.y = 0;
		p->drot.z = 0;
	}
	else if (keycode == 123) //Left
		p->transl.x -= TRANS_SIZE;
	else if (keycode == 124) //Right
		p->transl.x += TRANS_SIZE;
	else if (keycode == 126) //Up
		p->transl.y += TRANS_SIZE;
	else if (keycode == 125) //Down
		p->transl.y -= TRANS_SIZE;
	else if (keycode == 53) //Esc
		exit (0);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_param *p;

	(void)x;
	(void)y;
	p = (t_param*)param;

	if (button == 4)
		p->transl.z -= 1;
	else if (button == 5)
		p->transl.z += 1;
	return (0);
}


int main(int ac, char *av[])
{
	t_window *win;
	t_mlx mlx;
	t_env env;
	t_param param;

	(void)ac;
	(void)av;

	if (ac == 1)
		env.file = STDIN;
	else
	{
		if (!(env.file = f_openf(av[1], 'r')))
			f_eexit(0, "Invalid map name");
	}

	//parse_map(&env);
	parse_obj(&env);
	f_printf("%lu, %lu\n", env.map->verticies->total, env.map->indicies->total);

	mlx = get_mlx();
	win = create_window(1200, 1900, av[0]);

	param.map = env.map;
	param.win = win;
	param.rot.x = 0;
	param.rot.y = 0.15;
	param.rot.z = 0;
	param.drot.x = 0;
	param.drot.y = 0;
	param.drot.z = 0;
	param.transl.x = 0;
	param.transl.y = env.z * -0.5;
	param.transl.z = env.z * 1.05;
	param.scale.x = 1;
	param.scale.y = 1;
	param.scale.z = 1;
	mlx_mouse_hook(win->win, mouse_hook, &param);
	mlx_key_hook(win->win, key_hook, &param);
	mlx_loop_hook(get_mlx(), draw_loop, &param);
	mlx_loop(mlx);
	return (0);
}
