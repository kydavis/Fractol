/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:39:07 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/19 11:27:13 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>

/*
** frac_scale_c converts the x,y coordinates to their scaled
** r,i complex counterparts.
*/

void		frac_scale_c(t_mlx *mlx, t_complex *cp, int x, int y)
{
	cp->r = mlx->img.ctr.r +
		((double)x / (double)mlx->win.max_x - 0.5) * mlx->frc.zoom;
	cp->i = mlx->img.ctr.i +
		((double)y / (double)mlx->win.max_y - 0.5) * mlx->frc.zoom;
}

static int	frac_dispatcher(t_mlx *mlx, t_pix *p, t_complex *cp)
{
	t_complex	z;
	t_complex	zs;
	int			set;

	set = mlx->frc.id % 2;
	frac_scale_c(mlx, (set ? &z : cp), p->x, p->y);
	z.r = (set ? z.r : 0);
	z.i = (set ? z.i : 0);
	zs.r = z.r * z.r;
	zs.i = z.i * z.i;
	if (mlx->frc.id == 1 || mlx->frc.id == 2)
		return (julia(mlx, &z, cp, &zs));
	else if (mlx->frc.id == 3 || mlx->frc.id == 4)
		return (burning(mlx, &z, cp, &zs));
	else if (mlx->frc.id == 5 || mlx->frc.id == 6)
		return (lily(mlx, &z, cp, &zs));
	else if (mlx->frc.id == 7 || mlx->frc.id == 8)
		return (weird(mlx, &z, cp, &zs));
	return (0);
}

void		frac_printmap(t_mlx *mlx, t_complex *cp)
{
	t_pix		p;

	p.y = ~0;
	while (++p.y < mlx->win.max_y)
	{
		p.x = 0;
		while (p.x < mlx->win.max_x)
		{
			p.color = mlx->palette.large[frac_dispatcher(mlx, &p, cp)];
			pixel_to_img(mlx, &p);
			p.x += 1;
		}
	}
	mlx_put_image_to_window(mlx->id, mlx->win.id, mlx->img.id, 0, 0);
}
