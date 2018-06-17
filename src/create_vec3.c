/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 22:02:39 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/17 23:33:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_vector.h"
#include "f_memory.h"

t_vec3	*create_vec3(double x, double y, double z)
{
	t_vec3 *v3;

	v3 = (t_vec3*)f_memalloc(sizeof(*v3));
	v3->x = x;
	v3->y = y;
	v3->z = z;
	return (v3);
}
