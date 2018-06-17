/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:59:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 01:12:48 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VECTOR_H
# define S_VECTOR_H

# define NEW_POINT(x, y) &(t_point){(int)x, (int)y}

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

# define VEC3_TO_POINT(vec3) &(t_point){(int)vec3->x, (int)vec3->y}

typedef struct	s_vec3
{
	double x;
	double y;
	double z;
}				t_vec3;

t_vec3	*create_vec3(double x, double y, double z);

#endif
