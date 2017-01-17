/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:37:35 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/17 14:52:18 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>

int	frac_julia(t_mlx *c, t_pix *p, t_complex *cp, int mode)
{
	t_complex	z;
	t_complex	zs;
	int			max;
	int			i;

	frac_scale_c(c, &z, p->x, p->y);
	zs.r = z.r * z.r;
	zs.i = z.i * z.i;
	i = 0;
	max = ((mode == 1) ? 64 : 64);
	while (zs.r + zs.i < 4 && i < max)
	{
		z.i = z.r * z.i;
		z.i += z.i;
		z.i += cp->i;
		z.r = zs.r - zs.i + cp->r;
		zs.r = z.r * z.r;
		zs.i = z.i * z.i;
		i++;
	}
	return (i == max ? 256 : i);
}
