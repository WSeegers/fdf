/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 09:43:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"

static int	draw_loop(void *param)
{
	t_param		*p;
	t_line_list	*block1;

	p = (t_param*)param;
	p->rot.y =
		fmod((p->rot.y = p->rot.y + p->drot.y), 2);
	block1 = transform(p->map,
			p->scale,
			(t_vec3){p->rot.x * M_PI, p->rot.y * M_PI, p->rot.z * M_PI},
			p->transl);
	mlx_clear_window(get_mlx(), p->win->win);
	draw(p->win, block1);
	f_memdel((void**)&block1);
	return (0);
}

static void	init_param(t_param *param, t_window *win, t_env *env)
{
	param->map = env->map;
	param->win = win;
	param->rot.x = 0;
	param->rot.y = 0.15;
	param->rot.z = 0;
	param->drot.x = 0;
	param->drot.y = 0;
	param->drot.z = 0;
	param->transl.x = 0;
	param->transl.y = env->z * -0.5;
	param->transl.z = env->z * 1.05;
	param->scale.x = 1;
	param->scale.y = 1;
	param->scale.z = 1;
}

char		*get_extension(char *file_name)
{
	char *ext;

	if (file_name[0] == '.')
		file_name++;
	ext = f_strchr(file_name, '.');
	while (ext && f_strchr(ext + 1, '.'))
		ext = f_strchr(ext + 1, '.');
	return (ext);
}

int			main(int ac, char *av[])
{
	t_window	*win;
	t_mlx		mlx;
	t_env		env;
	t_param		param;

	if (ac == 1)
		f_printf("Usage: ./fdf file_name.{fdf/obj}");
	else
	{
		if (!(env.file = f_openf(av[1], 'r')))
			f_eexit(0, "Invalid map name");
	}
	if (!f_strcmp(get_extension(av[1]), ".fdf"))
		parse_map(&env);
	else if (!f_strcmp(get_extension(av[1]), ".obj") ||
					!f_strcmp(get_extension(av[1]), ".OBJ"))
		parse_obj(&env);
	mlx = get_mlx();
	win = create_window(1200, 1900, av[0]);
	init_param(&param, win, &env);
	mlx_mouse_hook(win->win, mouse_hook, &param);
	mlx_key_hook(win->win, key_hook, &param);
	mlx_loop_hook(get_mlx(), draw_loop, &param);
	mlx_loop(mlx);
	exit(0);
}
