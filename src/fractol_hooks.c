/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:45:15 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 19:03:31 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

/*
** exit_hook exits out of the progam using the cleanup function
*/

int	exit_hook(void *param)
{
	frac_cleanup(0, (t_mlx*)param);
	return (0);
}

/*
** motion_hook notices movement in the cursor and returns the position
** of the cursor.
*/

int	motion_hook(int x, int y, void *param)
{
	t_mlx *canvas;

	canvas = (t_mlx*)param;
	if (x <= 0 || x >= canvas->win.max_x || y <= 0 || y >= canvas->win.max_y ||
			canvas->frc.lock)
		return (0);
	frac_scale_c(canvas, &canvas->frc.cp, x, y);
	return (0);
}

/*
** fractol_mhooks is in charge of handling mouse hooks
*/

int	fractol_mhooks(int button, int x, int y, void *param)
{
	t_mlx *canvas;

	canvas = (t_mlx*)param;
	if (button == ZOOMOT || button == ZOOMIN)
		fractol_zoom(button, canvas, x, y);
	if (button == RCLICK)
		canvas->frc.lock = ~canvas->frc.lock;
	if (!(canvas->frc.lock))
		frac_scale_c(canvas, &canvas->frc.cp, x, y);
	return (0);
}

/*
** fractol_kr_hook is in charge of handling key hooks and turning off keys
*/

int	fractol_kr_hook(int kc, void *param)
{
	t_mlx	*can;

	can = (t_mlx*)param;
	if (kc == ESC)
		frac_cleanup(0, can);
	if ((kc == PS && can->frc.res < 256) || (kc == MS && can->frc.res > 64))
		can->frc.res += (kc == PS ? 64 : -64);
	if (kc == N1 || kc == N2 || kc == N3 || kc == N4 || kc == N5)
		frac_lpalette_loader(&can->palette, kc - N1, 4);
	if (kc == UA || kc == DA)
		can->img.ctr.i += (kc == DA ? can->frc.zoom : -can->frc.zoom) / 10;
	if (kc == LA || kc == RA)
		can->img.ctr.r += (kc == RA ? can->frc.zoom : -can->frc.zoom) / 10;
	if (kc == SPACE)
	{
		can->frc.zoom = 4;
		can->img.ctr.r = 0;
		can->img.ctr.i = 0;
	}
	return (0);
}

int	fractol_hook(void *param)
{
	t_mlx	*c;

	c = (t_mlx*)param;
	frac_printmap(c, &c->frc.cp);
	return (0);
}
