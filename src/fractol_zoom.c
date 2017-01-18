/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:04:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 13:35:49 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

void	fractol_zoom(int button, t_mlx *c, int x, int y)
{
	t_complex	cp;

	frac_scale_c(c, &cp, x, y);
	c->frc.zoom *= (button == ZOOMOT ? 1.1 : 0.9);
	c->img.ctr.r = cp.r - ((double)x / (double)c->win.max_x - 0.5) * c->frc.zoom;
	c->img.ctr.i = cp.i - ((double)y / (double)c->win.max_y - 0.5) * c->frc.zoom;
}
