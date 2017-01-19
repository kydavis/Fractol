/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:39:10 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/19 10:23:25 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>

/*
** frac_identifier identifies the fractal based on the argument
*/

static void	frac_identifier(t_mlx *c)
{
	if (!(ft_strcmp(c->frc.name, FRACTOL1)))
		c->frc.id = 1;
	else if (!(ft_strcmp(c->frc.name, FRACTOL2)))
		c->frc.id = 2;
	else if (!(ft_strcmp(c->frc.name, FRACTOL3)))
		c->frc.id = 3;
	else if (!(ft_strcmp(c->frc.name, FRACTOL4)))
		c->frc.id = 4;
	else if (!(ft_strcmp(c->frc.name, FRACTOL5)))
		c->frc.id = 5;
	else if (!(ft_strcmp(c->frc.name, FRACTOL6)))
		c->frc.id = 6;
	else if (!(ft_strcmp(c->frc.name, FRACTOL7)))
		c->frc.id = 7;
	else if (!(ft_strcmp(c->frc.name, FRACTOL8)))
		c->frc.id = 8;
	else
		frac_cleanup(1, c);
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
	if (!(c->win.id = mlx_new_window(c->mlx, x, y, c->frc.name)))
		frac_cleanup(2, c);
	if (!(c->img.id = mlx_new_image(c->mlx, x, y)))
		frac_cleanup(3, c);
	c->img.skt = mlx_get_data_addr(c->img.id,
			&c->img.bpp, &c->img.sl, &c->img.end);
	c->frc.res = 64;
	c->frc.zoom = 4;
	frac_identifier(c);
	frac_scale_c(c, &c->frc.cp, c->win.max_x / 2, c->win.max_y / 2);
	frac_printmap(c, &c->frc.cp);
}

int			main(int argc, char **argv)
{
	t_mlx	canvas;

	if (argc != 2)
		frac_cleanup(1, NULL);
	ft_bzero((void*)&canvas, sizeof(canvas));
	frac_color_palette(&canvas.palette);
	if (!(canvas.frc.name = ft_strdup(argv[1])))
		frac_cleanup(3, &canvas);
	frac_initialize(&canvas, MAX_X, MAX_Y);
	mlx_key_hook(canvas.win.id, fractol_kr_hook, (void*)&canvas);
	mlx_mouse_hook(canvas.win.id, fractol_mhooks, (void*)&canvas);
	mlx_hook(canvas.win.id, 6, 0, motion_hook, (void*)&canvas);
	mlx_hook(canvas.win.id, 17, 0, exit_hook, (void*)&canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
