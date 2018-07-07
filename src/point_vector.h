/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:59:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 10:10:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_VECTOR_H
# define POINT_VECTOR_H

# include <stddef.h>

# define POINT(x, y) (&(t_point){(int)x, (int)y})

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

# define VEC_TO_POINT(vec) (&(t_point){(int)vec->x, (int)vec->y})

typedef struct	s_vec2
{
	double x;
	double y;
}				t_vec2;

# define VEC2(x, y) (&(t_vec3){(double)x, (double)y})

typedef struct	s_vec3
{
	double x;
	double y;
	double z;
}				t_vec3;

# define VEC3(x, y, z) (&(t_vec3){(double)x, (double)y, (double)z})

t_vec3			*vec3_create(double x, double y, double z);
t_vec3			*vec3_copy(t_vec3 *vec);

#endif
