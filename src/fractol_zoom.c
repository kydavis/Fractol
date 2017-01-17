/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:04:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/17 14:46:58 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

void	fractol_zoom(int button, t_mlx *c, int x, int y)
{
	t_complex	cp;
	t_complex	db;
	float		zoom;

	frac_scale_c(c, &cp, x, y);
	zoom = (button == ZOOMOT ? (1 / 1.01) : 1.01);
	db.r = (c->border.max_r - c->border.min_r) / 2 / zoom;
	db.i = (c->border.max_i - c->border.min_i) / 2 / zoom;
	c->border.max_r = cp.r / 2 + db.r;
	c->border.max_i = cp.i / 2 + db.i;
	c->border.min_r = cp.r / 2 - db.r;
	c->border.min_i = cp.i / 2 - db.i;
	printf("max_r:%lf min_r:%lf max_i:%lf min_i:%lf\n", c->border.max_r,
			c->border.min_r, c->border.max_i, c->border.min_i);
	(void)x;
	(void)y;
}
