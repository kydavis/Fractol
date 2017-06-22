/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:45:15 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/19 13:48:47 by kdavis           ###   ########.fr       */
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
** of the cursor. Does not activate if the cursor is outside the window
** range, if the fractal is locked, or the fractal is not a Julia variant.
*/

int	motion_hook(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (x <= 0 || x >= mlx->win.max_x || y <= 0 || y >= mlx->win.max_y ||
			mlx->frc.lock || !(mlx->frc.id % 2))
		return (0);
	frac_scale_c(mlx, &mlx->frc.cp, x, y);
	frac_printmap(mlx);
	return (0);
}

/*
** fractol_mhooks is in charge of handling mouse hooks
*/

int	fractol_mhooks(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (button == ZOOMOT || button == ZOOMIN)
		fractol_zoom(button, mlx, x, y);
	if (button == RCLICK)
		mlx->frc.lock = ~mlx->frc.lock;
	if (!(mlx->frc.lock))
		frac_scale_c(mlx, &mlx->frc.cp, x, y);
	frac_printmap(mlx);
	return (0);
}

/*
** fractol_kr_hook is in charge of handling key hooks and turning off keys
*/

int	fractol_kr_hook(int kc, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (kc == ESC)
		frac_cleanup(0, mlx);
	if ((kc == PS && mlx->frc.res < 256) || (kc == MS && mlx->frc.res > 64))
		mlx->frc.res += (kc == PS ? 64 : -64);
	if (kc == N1 || kc == N2 || kc == N3 || kc == N4 || kc == N5)
		frac_lpalette_loader(&mlx->palette, kc - N1, 4);
	if (kc == UA || kc == DA)
		mlx->img.ctr.i += (kc == DA ? mlx->frc.zoom : -mlx->frc.zoom) / 10;
	if (kc == LA || kc == RA)
		mlx->img.ctr.r += (kc == RA ? mlx->frc.zoom : -mlx->frc.zoom) / 10;
	if (kc == RSHIFT)
		mlx->frc.trip = ~mlx->frc.trip;
	if (kc == SPACE)
	{
		mlx->frc.zoom = 4;
		mlx->img.ctr.r = 0;
		mlx->img.ctr.i = 0;
	}
	frac_printmap(mlx);
	return (0);
}
