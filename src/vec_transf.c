/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_transf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:46:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 06:28:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_gfx_matrix.h"

#include <stdio.h>
void	mat4_print(t_mat4 *m4);

void	vec2_transf(t_vec2 *v, t_mat3 *m)
{
	double x;
	double y;

	x = v->x;
	y = v->y;
	v->x = m->data[0][0] * x + m->data[0][1] *
			y + m->data[0][2];
	v->y = m->data[1][0] * x + m->data[1][1] *
			y + m->data[1][2];
}

void	vec3_transf(t_vec3 *v, t_mat4 *m)
{
	double x;
	double y;
	double z;

	x = v->x;
	y = v->y;
	z = v->z;
	//printf("(%f, %f, %f) -> ", v->x, v->y, v->z);
	v->x = (m->data[0][0] * x) + (m->data[0][1] *
			y) + (m->data[0][2] * z) + m->data[0][3];
	v->y = (m->data[1][0] * x) + (m->data[1][1] *
			y) + (m->data[1][2] * z) + m->data[1][3];
	v->z = (m->data[2][0] * x) + (m->data[2][1] *
			y) + (m->data[2][2] * z) + m->data[2][3];
	//printf("(%f, %f, %f)\n", v->x, v->y, v->z);
}
