/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 08:47:39 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 09:27:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfxwtc.h"
#include "controls.h"

static int	handle_rot(int keycode, t_param *p)
{
	if (keycode == KEY_A)
		p->drot.y += ROT_SPEED;
	else if (keycode == KEY_D)
		p->drot.y -= ROT_SPEED;
	else if (keycode == KEY_W)
		p->rot.x = fmod((p->rot.x += ROT_SPEED * 2), 2);
	else if (keycode == KEY_S)
		p->rot.x = fmod((p->rot.x -= ROT_SPEED * 2), 2);
	else if (keycode == KEY_Q)
		p->rot.z = fmod((p->rot.z += ROT_SPEED * 2), 2);
	else if (keycode == KEY_E)
		p->rot.z = fmod((p->rot.z -= ROT_SPEED * 2), 2);
	else if (keycode == KEY_SPACE)
	{
		p->drot.x = 0;
		p->drot.y = 0;
		p->drot.z = 0;
	}
	else
		return (0);
	return (1);
}

static int	handle_tansl_scale(int keycode, t_param *p)
{
	if (keycode == KEY_LEFT)
		p->transl.x -= TRANS_SIZE;
	else if (keycode == KEY_RIGHT)
		p->transl.x += TRANS_SIZE;
	else if (keycode == KEY_UP)
		p->transl.y += TRANS_SIZE;
	else if (keycode == KEY_DOWN)
		p->transl.y -= TRANS_SIZE;
	else if (keycode == PAD_PLUS)
		p->scale.y += 0.1;
	else if (keycode == PAD_MINUS)
		p->scale.y -= 0.1;
	else
		return (0);
	return (1);
}

int			key_hook(int keycode, void *param)
{
	t_param *p;

	p = (t_param*)param;
	if (handle_rot(keycode, p))
		;
	else if (handle_tansl_scale(keycode, p))
		;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int			mouse_hook(int button, int x, int y, void *param)
{
	t_param *p;

	(void)x;
	(void)y;
	p = (t_param*)param;
	if (button == 4)
		p->transl.z -= 1;
	else if (button == 5)
		p->transl.z += 1;
	return (0);
}
