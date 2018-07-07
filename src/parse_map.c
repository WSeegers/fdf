/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:30:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 10:09:52 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"
#include "f_math.h"

void				create_lines(t_line_list *map, size_t x_max, size_t z_max)
{
	size_t x;
	size_t z;
	size_t w;
	size_t w1;

	z = -1;
	while (++z < z_max - 1 && (x = -1))
	{
		w = z * x_max;
		w1 = (z + 1) * x_max;
		while (++x < x_max - 1)
		{
			llist_add_line(map, w + x, w + x + 1);
			llist_add_line(map, w + x, w1 + x);
		}
		llist_add_line(map, w + x, w1 + x);
	}
	x = -1;
	w = z * x_max;
	w1 = (z + 1) * x_max;
	while (++x < x_max - 1)
		llist_add_line(map, w + x, w + x + 1);
}

static t_line_list	*get_verticies(t_env *env)
{
	t_line_list		*map;
	char			*line;
	char			**split;
	size_t			x;
	size_t			z;

	map = line_list_create();
	z = -1;
	while (f_next_line(&line, env->file) && f_strlen(line) && (x = -1))
	{
		split = f_strsplit(line, ' ');
		++z;
		while (split[++x])
		{
			if (!f_isdigits(split[x]))
				f_eexit(0, "Map files need only contain digits");
			llist_add_vert(map, vec3_create(x, f_atoi(split[x]), z));
			env->max_y = f_max(f_atoi(split[x]), env->max_y);
		}
		f_strdel(&line);
		f_strarrdel(split);
	}
	env->x = x;
	env->z = ++z;
	return (map);
}

t_line_list			*parse_map(t_env *env)
{
	t_line_list		*map;

	env->max_y = 0;
	map = get_verticies(env);
	create_lines(map, env->x, env->z);
	env->map = transform(map,
			(t_vec3){1, 1, -1},
			(t_vec3){0, 0, 0},
			(t_vec3){-(env->x / 2.0), 0, env->z / 2.0});
	if (env->z * env->x != env->map->verticies->total)
		f_eexit(0, "Only square maps are viable");
	return (env->map);
}
