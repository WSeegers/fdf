/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_transf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:46:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 20:17:14 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_gfx_matrix.h"

#include <stdio.h>

void	vec2_transf(t_vec2 *v, t_mat3 *m)
{
	v->x = m->data[0][0] * v->x + m->data[0][1] *
			v->y + m->data[0][2];
	v->y = m->data[1][0] * v->x + m->data[1][1] *
			v->y + m->data[1][2];
}

void	vec3_transf(t_vec3 *v, t_mat4 *m)
{
	printf("(%f, %f, %f) -> ", v->x, v->y, v->z);
	v->x = m->data[0][0] * v->x + m->data[0][1] *
			v->y + m->data[0][2] * v->z + m->data[0][3];
	v->y = m->data[1][0] * v->x + m->data[1][1] *
			v->y + m->data[1][2] * v->z + m->data[1][3];
	v->z = m->data[2][0] * v->x + m->data[2][1] *
			v->y + m->data[2][2] * v->z + m->data[2][3];
	printf("(%f, %f, %f)\n", v->x, v->y, v->z);
}
