/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:15:13 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 10:01:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"
#include "f_math.h"
#include <stdlib.h>

void	parse_file(t_env *env, t_line_list *map)
{
	char *line;
	char **split;

	while (f_next_line(&line, env->file))
	{
		split = f_strsplit(line, ' ');
		if (!split[0])
			continue;
		if (!f_strcmp(split[0], "v"))
			llist_add_vert(map, vec3_create(atof(split[1]),
											atof(split[2]),
											atof(split[3])));
		else if (!f_strcmp(split[0], "f"))
		{
			llist_add_line(map, f_atoi(split[1]) - 1, f_atoi(split[2]) - 1);
			llist_add_line(map, f_atoi(split[2]) - 1, f_atoi(split[3]) - 1);
			llist_add_line(map, f_atoi(split[3]) - 1, f_atoi(split[1]) - 1);
		}
		f_strarrdel(split);
		f_strdel(&line);
	}
}

void	parse_obj(t_env *env)
{
	t_line_list		*map;

	map = line_list_create();
	parse_file(env, map);
	env->x = 1;
	env->max_y = 1;
	env->z = 2;
	env->map = transform(map,
			(t_vec3){1, 1, 1},
			(t_vec3){0, 0, 0},
			(t_vec3){0, 0, 0});
}
