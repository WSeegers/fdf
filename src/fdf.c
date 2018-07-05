/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/05 15:55:43 by wseegers         ###   ########.fr       */
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
	block1 = transform(p->cube, (t_vec3){1, 1, 1}, 
								(t_vec3){p->rot.x * M_PI, p->rot.y * M_PI, p->rot.z * M_PI}, 
								p->transl);
	mlx_clear_window(get_mlx(), p->win->win);
	draw(p->win, block1);
	f_memdel((void**)&block1);
	return (0);
}

#define ROT_SPEED 0.01
#define TRANS_SIZE 1

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
		//p->drot.y = fmod((p->drot.y -= ROT_SPEED), 2);
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


int main(void)
{
	t_window *win;
	t_mlx mlx;
	t_env env;
	
	mlx = get_mlx();
	win = create_window(1200, 1900, "WINDOW!!");

	t_line_list *map = parse_map(&env);

	t_param param;
	param.cube = map;
	param.win = win;
	param.rot.x = 0;
	param.rot.y = 0.15;
	param.rot.z = 0;
	param.drot.x = 0;
	param.drot.y = 0;
	param.drot.z = 0;
	param.transl.x = 0;
	param.transl.y = -100;
	param.transl.z = env.z * 1;
	param.scale.x = 1;
	param.scale.y = 1;
	param.scale.z = 1;
	
	mlx_mouse_hook(win->win, mouse_hook, &param);
	mlx_key_hook(win->win, key_hook, &param);
	mlx_loop_hook(get_mlx(), draw_loop, &param);
	mlx_loop(mlx);
	return (0);
}
