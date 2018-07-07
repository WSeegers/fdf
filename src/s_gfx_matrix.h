/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_gfx_matrix.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:05:05 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 10:04:06 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_GFX_MATRIX_H
# define S_GFX_MATRIX_H

# include "point_vector.h"

typedef struct	s_mat3
{
	double data[3][3];
}				t_mat3;

t_mat3			*mat3_create(void);
void			mat3_init_id(t_mat3 *m3);
t_mat3			*mat3_mul(t_mat3 *m1, t_mat3 *m2);
void			vec2_transf(t_vec2 *v, t_mat3 *m);

typedef struct	s_mat4
{
	double data[4][4];
}				t_mat4;

t_mat4			*mat4_create(void);
void			mat4_init_id(t_mat4 *m4);
t_mat4			*mat4_mul(t_mat4 *m1, t_mat4 *m2);
void			vec3_transf(t_vec3 *v, t_mat4 *m);

#endif
