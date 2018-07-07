/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_window.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 22:44:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 09:56:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_WINDOW_H
# define S_WINDOW_H

typedef void	*t_win;

typedef struct	s_window
{
	t_win	win;
	int		height;
	int		width;
	double	xscale;
	double	yscale;
}				t_window;

t_window		*create_window(int height, int width, char *title);

#endif
