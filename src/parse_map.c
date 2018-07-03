/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:30:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 19:01:02 by wseegers         ###   ########.fr       */
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
			printf("line: %lu -> %lu\n", w + x, w + x + 1);
			llist_add_line(map, w + x, w1 + x );
			printf("line: %lu -> %lu\n", w + x, w1 + x);
		}
		llist_add_line(map, w + x, w1 + x );
	}
	x = -1;
	w = z * x_max;
	w1 = (z + 1) * x_max;
	while (++x < x_max - 1)
	{
		llist_add_line(map, w + x, w + x + 1);
		printf("line: %lu -> %lu\n", w + x, w + x + 1);
	}
	//llist_add_line(map, w + x, w1 + x );

}


t_line_list	*parse_map(void)
{
	char			*line;
	t_line_list		*map;
	char			**split;
	size_t			x;
	size_t			z;

	map = line_list_create();
	z = -1;
	while (f_next_line(&line, STDIN) && f_strlen(line) && (x = -1))
	{
		split = f_strsplit(line, ' ');
		++z;
		while (split[++x])
			llist_add_vert(map, vec3_create(x, f_atoi(split[x]), z));
		f_strdel(&line);
		f_strarrdel(split);
	}
	create_lines(map, x, ++z);
	return (map);
}
