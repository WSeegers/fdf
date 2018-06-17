/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 00:16:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 01:03:15 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "f_memory.h"

t_cube	*create_cube(double size)
{
	t_cube *cube;
	double halfsize;

	halfsize = size / 2.0;
	cube = (t_cube*)f_memalloc(sizeof(*cube));
	cube->vector[0] = create_vec3(-halfsize, halfsize, -halfsize);
	cube->vector[1] = create_vec3(halfsize, halfsize, -halfsize);
	cube->vector[2] = create_vec3(halfsize, -halfsize, -halfsize);
	cube->vector[3] = create_vec3(-halfsize, -halfsize, -halfsize);
	cube->vector[4] = create_vec3(-halfsize, halfsize, halfsize);
	cube->vector[5] = create_vec3(halfsize, halfsize, halfsize);
	cube->vector[6] = create_vec3(halfsize, -halfsize, halfsize);
	cube->vector[7] = create_vec3(-halfsize, -halfsize, halfsize);
	return (cube);
}
