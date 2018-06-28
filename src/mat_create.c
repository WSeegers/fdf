/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:08:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 19:11:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_gfx_matrix.h"
#include "f_memory.h"

t_mat3	*mat3_create(void)
{
	t_mat3 *m3;

	m3 = (t_mat3*)f_memalloc(sizeof(*m3));
	return (m3);
}

t_mat4	*mat4_create(void)
{
	t_mat4 *m4;

	m4 = (t_mat4*)f_memalloc(sizeof(*m4));
	return (m4);
}
