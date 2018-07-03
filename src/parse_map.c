/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:30:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 14:12:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"

#include <stdio.h>

void	create_lines(t_line_list *map, size_t x_max, size_t z_max)
{
	size_t x;
	size_t z;

	z = -1;
	while (++z < z_max - 1 && (x = -1))
	{
		while (++x < x_max - 1)
		{
			llist_add_line(map, x, x + 1);
			llist_add_line(map, x, (z * x_max) + x);
			//printf("%lu->%lu\n", x, x + 1);
			//printf("%lu->%lu\n", x, ((z + 1) * x_max) + x);
		}
	}
}


t_line_list	*parse_map(void)
{
	char			*line;
	t_line_list		*map;
	char			**split;
	size_t			x;
	size_t			z;
t_vec3 *vt;
t_vec3 *v;
	map = line_list_create();
	z = -1;
	while (f_next_line(&line, STDIN) && f_strlen(line) && (x = -1))
	{
		split = f_strsplit(line, ' ');
		++z;
		while (split[++x])
		{
			
			//printf("(%lu, %d, %lu)\n", x, f_atoi(split[x]), z);
			llist_add_vert(map, (v = vec3_create(x, f_atoi(split[x]), z)));
			//printf("(%f, %f, %f)\n", vec->x, vec->y, vec->z);
			vt = LLIST_GET(map, 1);
			//printf("new (%f, %f, %f) [%lu] %p\n", vt->x, vt->y, vt->z, map->indicies->total, vt);
			//printf("\t\tpull (%f, %f, %f) [%lu] %p\n", v->x, v->y, v->z, map->indicies->total, v);
		}
		f_strdel(&line);
		f_strarrdel(split);
	}
	vt = LLIST_GET(map, 0);
	printf("preline (%f, %f, %f) [%lu] %p\n", vt->x, vt->y, vt->z, map->indicies->total, vt);
	vt = (t_vec3*)map->verticies->data[0];
	printf("pre_lines (%f, %f, %f)\n", vt->x, vt->y, vt->z);
	create_lines(map, x, z);
	return (map);
}
