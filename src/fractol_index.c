/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:39:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 18:08:37 by kdavis           ###   ########.fr       */
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
	cp->r = c->img.ctr.r + ((double)x / (double)c->win.max_x - 0.5) * c->frc.zoom;
	cp->i = c->img.ctr.i + ((double)y / (double)c->win.max_y - 0.5) * c->frc.zoom;
}

static int	frac_dispatcher(t_mlx *c, t_pix *p, t_complex *cp)
{
	t_complex	z;
	t_complex	zs;
	int			set;

	set = c->frc.id % 2;
	frac_scale_c(c, (set ? &z : cp), p->x, p->y);
	z.r = (set ? z.r : 0);
	z.i = (set ? z.i : 0);
	zs.r = z.r * z.r;
	zs.i = z.i * z.i;
	if (c->frc.id == 1 || c->frc.id == 2)
		return (frac_julia(c, &z, cp, &zs)); 
	else if (c->frc.id == 3 || c->frc.id == 4)
		return (frac_burning(c, &z, cp, &zs)); 
	else if (c->frc.id == 5 || c->frc.id == 6)
		return (frac_lily(c, &z, cp, &zs)); 
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
