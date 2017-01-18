/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:45:15 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 13:35:09 by kdavis           ###   ########.fr       */
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
	frac_printmap(canvas, &canvas->frc.cp);
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
	{
		frac_scale_c(canvas, &canvas->frc.cp, x, y);
	}
	frac_printmap(canvas, &canvas->frc.cp);
/*	ft_printf("x:%d, y:%d, button:%d\n", x, y, button);*/
	return (0);
}


/*
** fractol_khooks is in charge of handling key hooks (mainly the esc command)
*/

int	fractol_khooks(int kc, void *param)
{
	t_mlx	*canvas;

	canvas = (t_mlx*)param;
	if (kc == ESC)
		frac_cleanup(0, canvas);
	if ((kc == PS && canvas->frc.res < 256) || (kc == MS && canvas->frc.res > 64))
		canvas->frc.res += (kc == PS ? 64 : -64);
	if (kc == N1 || kc == N2 || kc == N3 || kc == N4 || kc == N5)
		frac_lpalette_loader(&canvas->palette, kc - N1, 4);
	if (kc == UA || kc == DA)
		canvas->img.ctr.i += (kc == DA ? canvas->frc.zoom : -canvas->frc.zoom) / 100;
	if (kc == LA || kc == RA)
		canvas->img.ctr.r += (kc == RA ? canvas->frc.zoom : -canvas->frc.zoom) / 100;
	frac_printmap(canvas, &canvas->frc.cp);
	return (0);
}
