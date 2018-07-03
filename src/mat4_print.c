/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 05:43:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/03 05:56:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gfxwtc.h"

void	mat4_print(t_mat4 *m4)
{
	int i;
	int j;

	i = -1;
	while (++i < 4 && (j = -1))
	{
		printf("|");
		while (++j < 4)
			printf (" %f |", m4->data[i][j]);
		printf("\n");
	}
}
