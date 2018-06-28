/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 22:02:39 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/27 18:30:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point_vector.h"
#include "f_memory.h"

t_vec3	*vec3_create(double x, double y, double z)
{
	t_vec3 *v3;

	v3 = (t_vec3*)f_memalloc(sizeof(*v3));
	v3->x = x;
	v3->y = y;
	v3->z = z;
	return (v3);
}
