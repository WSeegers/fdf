/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:14:44 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/02 14:19:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point_vector.h"

t_vec3	*vec3_copy(t_vec3 *vec)
{
	t_vec3 *copy;

	copy = vec3_create(vec->x, vec->y, vec->z);
	return (copy);
}
