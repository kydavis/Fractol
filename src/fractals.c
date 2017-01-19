/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:37:35 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 19:05:44 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>
#include <fractol.h>

/*
** All of the fractals are variants of what happens when you mess with
** the formula for the Julia set in different ways.
*/

int	julia(t_mlx *c, t_complex *z, t_complex *cp, t_complex *zs)
{
	int			i;

	i = 0;
	while (zs->r + zs->i < 4 && i < c->frc.res)
	{
		z->i = z->r * z->i;
		z->i += z->i;
		z->i += cp->i;
		z->r = zs->r - zs->i + cp->r;
		zs->r = z->r * z->r;
		zs->i = z->i * z->i;
		i++;
	}
	return (i == c->frc.res ? 256 : i);
}

int	burning(t_mlx *c, t_complex *z, t_complex *cp, t_complex *zs)
{
	int			i;

	i = 0;
	while (zs->r + zs->i < 10 && i < c->frc.res)
	{
		z->i = fabs(z->r * z->i);
		z->i += z->i;
		z->i += cp->i;
		z->r = zs->r - zs->i + cp->r;
		zs->r = z->r * z->r;
		zs->i = z->i * z->i;
		i++;
	}
	return (i == c->frc.res ? 256 : i);
}

int	lily(t_mlx *c, t_complex *z, t_complex *cp, t_complex *zs)
{
	int			i;

	i = 0;
	while (zs->r + zs->i < 10 && i < c->frc.res)
	{
		z->i = z->r * z->i;
		z->i += z->i;
		z->i += cp->i;
		z->r = fabs(zs->r - zs->i) + cp->r;
		zs->r = z->r * z->r;
		zs->i = z->i * z->i;
		i++;
	}
	return (i == c->frc.res ? 256 : i);
}

int	weird(t_mlx *c, t_complex *z, t_complex *cp, t_complex *zs)
{
	int			i;

	i = 0;
	while (zs->r + zs->i < 10 && i < c->frc.res)
	{
		z->r = zs->r - zs->i + cp->r;
		z->i = z->r * z->i;
		z->i += z->i;
		z->i += cp->i;
		zs->r = z->r * z->r;
		zs->i = z->i * z->i;
		i++;
	}
	return (i == c->frc.res ? 256 : i);
}
