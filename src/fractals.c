/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:37:35 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 16:00:13 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>

int	frac_julia(t_mlx *c, t_pix *p, t_complex *cp, int frac)
{
	t_complex	z;
	t_complex	zs;
	int			i;

	frac_scale_c(c, (frac ? &z : cp), p->x, p->y);
	z.r = (frac ? z.r : 0);
	z.i = (frac ? z.i : 0);
	zs.r = z.r * z.r;
	zs.i = z.i * z.i;
	i = 0;
	while (zs.r + zs.i < 4 && i < c->frc.res)
	{
		z.i = z.r * z.i;
		z.i += z.i;
		z.i += cp->i;
		z.r = zs.r - zs.i + cp->r;
		zs.r = z.r * z.r;
		zs.i = z.i * z.i;
		i++;
	}
	return (i == c->frc.res ? 256 : i);
}
