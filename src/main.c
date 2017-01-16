/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:39:10 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/15 15:15:10 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>

/*
** fractol_mhooks is in charge of handling mouse hooks 
*/
static int	fractol_mhooks(int button, int x, int y, void *param)
{
	t_mlx *canvas;

	canvas = (t_mlx*)param;
/*	frac_dispatcher(c);*/
	ft_printf("x:%d, y:%d, button:%d\n",x, y, button);
	mlx_put_image_to_window(canvas->mlx, canvas->win.id, canvas->img.id, 0, 0);
	return (0);
}


/*
** fractol_khooks is in charge of handling key hooks (mainly the esc command)
*/

static int	fractol_khooks(int kc, void *param)
{
	t_mlx	*canvas;

	canvas = (t_mlx*)param;
	if (kc == ESC)
		frac_cleanup(0, canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->win.id, canvas->img.id, 0, 0);
	return (0);
}

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
}

int			main(int argc, char **argv)
{
	t_mlx	canvas;

	if (argc != 2)
		frac_cleanup(1, NULL);
	ft_bzero((void*)&canvas, sizeof(canvas));
	frac_color_palette(canvas->palette);
	if (!(canvas.name = ft_strdup(argv[1])))
		frac_cleanup(3, &canvas);
	frac_initialize(&canvas, MAX_X, MAX_Y);
	mlx_key_hook(canvas.win.id, fractol_khooks, (void*)&canvas);
	mlx_mouse_hook(canvas.win.id, fractol_mhooks, (void*)&canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
