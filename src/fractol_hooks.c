/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:45:15 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/17 11:50:27 by kdavis           ###   ########.fr       */
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
	if (x <= 0 || x >= canvas->win.max_x || y <= 0 || y >= canvas->win.max_y)
		return (0);
	frac_printmap(canvas, x, y, 0);
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
	frac_printmap(canvas, x, y, 1);
/*	ft_printf("x:%d, y:%d, button:%d\n",x, y, button);*/
	return (0);
	(void)button;
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
	mlx_put_image_to_window(canvas->mlx, canvas->win.id, canvas->img.id, 0, 0);
	return (0);
}
