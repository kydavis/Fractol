/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 10:34:38 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/13 14:23:55 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>

int	pixel_to_img(t_mlx *c, t_pix *p)
{
	int	*pix;

	if (p->x >= c->win.max_x || p->y >= c->win.max_y || p->x < 0 || p->y < 0)
		return (0);
	pix = (int *)(c->img.skt + (c->img.bpp / 8 * p->x) + (c->img.sl * p->y));
	*pix = p->color;
	return (1);
}
