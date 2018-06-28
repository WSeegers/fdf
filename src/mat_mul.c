/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:21:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 19:30:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_gfx_matrix.h"

t_mat3	*mat3_mul(t_mat3 *m1, t_mat3 *m2)
{
	t_mat3 *ret;
	int col;
	int row;
	int i;

	ret = mat3_create();
	row = -1;
	while (++row < 3 && (col = -1))
		while (++col < 3 && (i = -1))
			while (++i < 3)
				ret->data[row][col] += m1->data[row][i] * m2->data[i][col];
	return (ret);
}

t_mat4	*mat4_mul(t_mat4 *m1, t_mat4 *m2)
{
	t_mat4 *ret;
	int col;
	int row;
	int i;

	ret = mat4_create();
	row = -1;
	while (++row < 4 && (col = -1))
		while (++col < 4 && (i = -1))
			while (++i < 4)
				ret->data[row][col] += m1->data[row][i] * m2->data[i][col];
	return (ret);
}
