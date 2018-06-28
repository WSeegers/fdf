/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:30:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 15:31:36 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h" 
#include "s_list.h"
#include "f_string.h"
#include "f_io.h"
#include "f_memory.h"

static void	parse_lines(t_vec3_grid *map, t_list *temp)
{
	char	**split;
	char 	*line;
	size_t		col;
	size_t		row;

	row = -1;
	while ((line = (char*)s_list_pop(temp, 0)))
				
	{
		split = f_strsplit(line, ' ');
		f_strdel(&line);
		++row;
		col = -1;
		while (split[++col])
			*GRID(map, row, col) =
				(t_vec3){col, (f_atoi(split[col]), row};
		f_strarrdel(split);
	}
}

static size_t	get_width(char *line)
{
	size_t	width;

	width = 1;
	while ((line = f_strchr(line, ' ')))
	{
		line++;
		width++;
	}
	return (width);
}

t_vec3_grid	*parse_map(void)
{
	char			*line;
	t_list			*temp_map;
	size_t			height;
	size_t			width;
	t_vec3_grid	*map;

	temp_map = s_list_create(NULL);
	//TODO: error checking here
	width = 0;
	while (f_next_line(&line, STDIN) && f_strlen(line))
	{
		if (!width)
			width = get_width(line);
		s_list_append(temp_map, line);
	}
	height = temp_map->size;
	map = vec3_grid_create(height, width);
	parse_lines(map, temp_map);
	f_memdel((void**)&temp_map);
	return (map);
}
