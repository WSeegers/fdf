/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cube.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 00:11:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 01:10:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CUBE_H
# define S_CUBE_H

typedef struct	s_cube
{
	t_vec3 *vector[8];
}				t_cube;

t_cube	*create_cube(double size);
void	draw_cube(t_window *win, t_cube *cube);

#endif
