/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:04:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/22 11:27:00 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fractol_zoom(int button, t_mlx *mlx, int x, int y)
{
	t_complex	cp;

	frac_scale_c(mlx, &cp, x, y);
	mlx->frc.zoom *= (button == ZOOMOT ? 1.1 : 0.9);
	mlx->img.ctr.r = cp.r -
		((double)x / (double)mlx->win.max_x - 0.5) * mlx->frc.zoom;
	mlx->img.ctr.i = cp.i -
		((double)y / (double)mlx->win.max_y - 0.5) * mlx->frc.zoom;
}
