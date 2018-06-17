/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:39:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/17 14:41:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfxwtc.h"

t_mlx	get_mlx(void)
{
	static t_mlx	mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}
