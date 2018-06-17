/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 22:35:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/17 22:43:27 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
# define COLOURS_H

/*
** Colours are defined as | RED | GREEN | BLUE | and range between
** 0 and 255
*/

typedef int			t_colour;

# define RGB(r, g, b) (((r & 0xff) << 16) & ((g & 0xff) << 8) & (b & 0xff))

# define P_WHITE	0xffffff
# define P_RED		0xff0000
# define P_GREEN	0x00ff00
# define P_BLUE		0x0000ff

#endif
