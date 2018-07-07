/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:45:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 09:49:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"

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
