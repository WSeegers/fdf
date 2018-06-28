/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_grid_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 04:58:01 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 05:23:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"
#include "f_memory.h"

t_vec3_grid	*vec3_grid_create(size_t rows, size_t cols)
{
	t_vec3_grid *grid;
	size_t size;
	
	size = rows * cols;
	grid = (t_vec3_grid*)f_memalloc(sizeof(*grid));
	grid->plane = (t_vec3*)f_memalloc(sizeof(*grid->plane) * size);
	grid->rows = rows;
	grid->cols = cols;
	grid->size = size;
	return (grid);
}
