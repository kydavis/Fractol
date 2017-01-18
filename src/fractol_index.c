/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:39:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 15:17:49 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>
#include <stdio.h>///

/*
** frac_scale_c converts the x,y coordinates to their scaled
** r,i complex counterparts.
*/

void	frac_scale_c(t_mlx *c, t_complex *cp, int x, int y)
{
/*	t_complex	db;

	db.r = cv->border.max_r - cv->border.min_r;
	db.i = cv->border.max_i - cv->border.min_i;*/
/*	c->r = (db.r / (double)cv->win.max_x) * x + cv->border.min_r;
	c->i = -1 * ((db.i / (double)cv->win.max_y) * y + cv->border.min_i);*/
	cp->r = c->img.ctr.r + ((double)x / (double)c->win.max_x - 0.5) * c->frc.zoom;
	cp->i = c->img.ctr.i + ((double)y / (double)c->win.max_y - 0.5) * c->frc.zoom;
}

static int	frac_dispatcher(t_mlx *c, t_pix *p, t_complex *cp)
{
	if (c->frc.id == 1)
		return (frac_julia(c, p, cp)); 
/*	else if (c->frc.id == 2)
		frac_mandelbrot(c); */
/*	else if (c->frc.id == 3)
		return (test_fractol(c, cp));*/
	return (0);
}

void	frac_printmap(t_mlx *c, t_complex *cp)
{
/*	t_complex	cp;*/
	t_pix		p;

	p.y = ~0;
/*	frac_scale_c(c, &cp, x, y);*/
	while (++p.y < c->win.max_y)
	{
		p.x = 0;
		while (p.x < c->win.max_x)
		{
			p.color = c->palette.large[frac_dispatcher(c, &p, cp)];
			pixel_to_img(c, &p);
			p.x += 1;
		}
	}
	mlx_put_image_to_window(c->mlx, c->win.id, c->img.id, 0, 0);
}
