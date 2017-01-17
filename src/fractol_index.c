/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:39:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/17 11:51:10 by kdavis           ###   ########.fr       */
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

void	frac_scale_c(t_mlx *cv, t_complex *c, int x, int y)
{
	t_complex	db;

	db.r = cv->border.max_r - cv->border.min_r;
	db.i = cv->border.max_i - cv->border.min_i;
	c->r = (db.r / (double)cv->win.max_x) * x + cv->border.min_r;
	c->i = -1 * ((db.i / (double)cv->win.max_y) * y + cv->border.min_i);
}

static int	frac_dispatcher(t_mlx *c, t_pix *p, t_complex *cp, int mode)
{
	if (!(ft_strcmp(c->win.name, FRACTOL1)))
		return (frac_julia(c, p, cp, mode)); 
/*	else if (!(ft_strcmp(c->name, FRACTOL2)
		frac_mandelbrot(c); */
	else if (!(ft_strcmp(c->win.name, FRACTOL3)))
		return (test_fractol(c, cp));
	else
		frac_cleanup(1, c);
	return (0);
}

/*void	five_bytes(t_mlx *c, t_pix *p, t_complex *cp)
{
	t_pix	pixel[4];

	pixel[0].x = p->x + 1;
	pixel[0].y = p->y;
	pixel[1].x = p->x + 2;
	pixel[1].y = p->y;
	pixel[2].x = p->x + 3;
	pixel[2].y = p->y;
	pixel[3].x = p->x + 4;
	pixel[3].y = p->y;
	p->color = c->palette.large[frac_dispatcher(c, p, cp)];
	pixel[0].color = c->palette.large[frac_dispatcher(c, pixel, cp)];
	pixel[1].color = c->palette.large[frac_dispatcher(c, pixel + 1, cp)];
	pixel[2].color = c->palette.large[frac_dispatcher(c, pixel + 2, cp)];
	pixel[3].color = c->palette.large[frac_dispatcher(c, pixel + 3, cp)];
	pixel_to_img(c, p);
	pixel_to_img(c, pixel);
	pixel_to_img(c, pixel + 1);
	pixel_to_img(c, pixel + 2);
	pixel_to_img(c, pixel + 3);
}*/

void	frac_printmap(t_mlx *c, int x, int y, int mode)
{
	t_complex	cp;
	t_pix		p;

	frac_scale_c(c, &cp, x, y);
	p.y = ~0;
	while (++p.y < c->win.max_y)
	{
		p.x = 0;
		while (p.x < c->win.max_x)
		{
/*			five_bytes(c, &p, &cp);*/
			p.color = c->palette.large[frac_dispatcher(c, &p, &cp, mode)];
			pixel_to_img(c, &p);
			p.x += 1;
		}
	}
	mlx_put_image_to_window(c->mlx, c->win.id, c->img.id, 0, 0);
}
