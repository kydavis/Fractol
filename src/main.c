/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:39:10 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/17 11:53:00 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>


/*
** frac_initialize is used to initialize the mlx server, the window, and the
** image.
*/

static void	frac_initialize(t_mlx *c, int x, int y)
{
	c->mlx = mlx_init();
	c->win.max_x = x;
	c->win.max_y = y;
	if (!(c->win.id = mlx_new_window(c->mlx, x, y, "fractol")))
		frac_cleanup(2, c);
	if (!(c->img.id = mlx_new_image(c->mlx, x, y)))
		frac_cleanup(3, c);
	c->img.skt = mlx_get_data_addr(c->img.id,
			&c->img.bpp, &c->img.sl, &c->img.end);
	c->border.max_r = 2;
	c->border.min_r = -2;
	c->border.max_i = 2;
	c->border.min_i = -2;
	frac_printmap(c, c->win.max_x / 2, c->win.max_y / 2, 1);
}

int			main(int argc, char **argv)
{
	t_mlx	canvas;

	if (argc != 2)
		frac_cleanup(1, NULL);
	ft_bzero((void*)&canvas, sizeof(canvas));
	frac_color_palette(&canvas.palette);
	if (!(canvas.win.name = ft_strdup(argv[1])))
		frac_cleanup(3, &canvas);
	frac_initialize(&canvas, MAX_X, MAX_Y);
	mlx_key_hook(canvas.win.id, fractol_khooks, (void*)&canvas);
	mlx_mouse_hook(canvas.win.id, fractol_mhooks, (void*)&canvas);
	mlx_hook(canvas.win.id, 6, 0, motion_hook, (void*)&canvas);
	mlx_hook(canvas.win.id, 17, 0, exit_hook, (void*)&canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
