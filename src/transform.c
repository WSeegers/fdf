/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 07:15:57 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 06:13:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "f_memory.h"

//void	mat4_print(t_mat4 *m4);

t_mat4 *get_scale_mat(t_vec3 scale)
{
	t_mat4 *mat_scale;

	mat_scale = mat4_create();
	mat_scale->data[0][0] = scale.x;
	mat_scale->data[0][1] = 0.0;
	mat_scale->data[0][2] = 0.0;
	mat_scale->data[0][3] = 0.0;
	mat_scale->data[1][0] = 0.0;
	mat_scale->data[1][1] = scale.y;
	mat_scale->data[1][2] = 0.0;
	mat_scale->data[1][3] = 0.0;
	mat_scale->data[2][0] = 0.0;
	mat_scale->data[2][1] = 0.0;
	mat_scale->data[2][2] = scale.z;
	mat_scale->data[2][3] = 0.0;
	mat_scale->data[3][0] = 0.0;
	mat_scale->data[3][1] = 0.0;
	mat_scale->data[3][2] = 0.0;
	mat_scale->data[3][3] = 1.0;
	return (mat_scale);
}

void	rotate_x(t_mat4 *m4, double rad)
{
	m4->data[0][0] = 1.0;
	m4->data[0][1] = 0.0;
	m4->data[0][2] = 0.0;
	m4->data[0][3] = 0.0;

	m4->data[1][0] = 0.0;
	m4->data[1][1] = cos(rad);
	m4->data[1][2] = -sin(rad);
	m4->data[1][3] = 0.0;

	m4->data[2][0] = 0.0;
	m4->data[2][1] = sin(rad);
	m4->data[2][2] = cos(rad);
	m4->data[2][3] = 0.0;

	m4->data[3][0] = 0.0;
	m4->data[3][1] = 0.0;
	m4->data[3][2] = 0.0;
	m4->data[3][3] = 1.0;
}

void	rotate_y(t_mat4 *m4, double rad)
{
	m4->data[0][0] = cos(rad);
	m4->data[0][1] = 0.0;
	m4->data[0][2] = sin(rad);
	m4->data[0][3] = 0.0;

	m4->data[1][0] = 0.0;
	m4->data[1][1] = 1.0;
	m4->data[1][2] = 0.0;
	m4->data[1][3] = 0.0;

	m4->data[2][0] = -sin(rad);
	m4->data[2][1] = 0.0;
	m4->data[2][2] = cos(rad);
	m4->data[2][3] = 0.0;

	m4->data[3][0] = 0.0;
	m4->data[3][1] = 0.0;
	m4->data[3][2] = 0.0;
	m4->data[3][3] = 1.0;
}

void	rotate_z(t_mat4 *m4, double rad)
{
	m4->data[0][0] = cos(rad);
	m4->data[0][1] = -sin(rad);
	m4->data[0][2] = 0.0;
	m4->data[0][3] = 0.0;

	m4->data[1][0] = sin(rad);
	m4->data[1][1] = cos(rad);
	m4->data[1][2] = 0.0;
	m4->data[1][3] = 0.0;

	m4->data[2][0] = 0.0;
	m4->data[2][1] = 0.0;
	m4->data[2][2] = 1.0;
	m4->data[2][3] = 0.0;

	m4->data[3][0] = 0.0;
	m4->data[3][1] = 0.0;
	m4->data[3][2] = 0.0;
	m4->data[3][3] = 1.0;
}

t_mat4 *get_rot_mat(t_vec3 rot)
{
	t_mat4 *mat_rot;
	t_mat4 temp;
	t_mat4 *temp_rot;
	
	temp_rot = mat4_create();
	mat4_init_id(temp_rot);

	rotate_y(&temp, rot.y);
	mat_rot = mat4_mul(temp_rot, &temp);
	f_memdel((void**)&temp_rot);

	rotate_x(&temp, rot.x);
	temp_rot = mat4_mul(mat_rot, &temp);
	f_memdel((void**)&mat_rot);

	rotate_z(&temp, rot.z);
	mat_rot = mat4_mul(temp_rot, &temp);
	f_memdel((void**)&temp_rot);

	return (mat_rot);
}

t_mat4 *get_transl_mat(t_vec3 transl)
{
	t_mat4 *mat_transl;

	mat_transl = mat4_create();
	mat_transl->data[0][0] = 1.0;
	mat_transl->data[0][1] = 0.0;
	mat_transl->data[0][2] = 0.0;
	mat_transl->data[0][3] = transl.x;
	mat_transl->data[1][0] = 0.0;
	mat_transl->data[1][1] = 1.0;
	mat_transl->data[1][2] = 0.0;
	mat_transl->data[1][3] = transl.y;
	mat_transl->data[2][0] = 0.0;
	mat_transl->data[2][1] = 0.0;
	mat_transl->data[2][2] = 1.0;
	mat_transl->data[2][3] = transl.z;
	mat_transl->data[3][0] = 0.0;
	mat_transl->data[3][1] = 0.0;
	mat_transl->data[3][2] = 0.0;
	mat_transl->data[3][3] = 1.0;
	return (mat_transl);
}

t_line_list	*apply_transform(t_line_list *llist, t_mat4 *transf)
{
	t_line_list *ret;
	size_t		i;

	ret = line_list_create();
	i = -1;
	while (++i < llist->verticies->total)
	{
		llist_add_vert(ret, vec3_copy(LLIST_VGET(llist, i)));
		vec3_transf(LLIST_VGET(ret, i), transf);
	}
	i = -1;
	while (++i < llist->indicies->total)
		vector_add(ret->indicies, (void*)LLIST_IGET(llist, i));	
	return (ret);
}

t_line_list *transform(t_line_list *llist, t_vec3 scale,
										t_vec3 rot, t_vec3 transl)
{
	t_mat4 *mat_transf;
	t_mat4 *mat_scale;
	t_mat4 *mat_rot;
	t_mat4 *mat_transl;
	t_mat4 *mat_temp;
	
	mat_scale = get_scale_mat(scale);
	mat_rot = get_rot_mat(rot);
	mat_transl = get_transl_mat(transl);

	mat_temp = mat4_mul(mat_transl, mat_rot);
	mat_transf = mat4_mul(mat_temp, mat_scale);

	f_memdel((void**)&mat_scale);
	f_memdel((void**)&mat_rot);
	f_memdel((void**)&mat_transl);
	f_memdel((void**)&mat_temp);
	
	llist = apply_transform(llist, mat_transf);
	f_memdel((void**)&mat_transf);
	return (llist);
}
