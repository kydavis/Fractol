/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:39:10 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/22 12:01:21 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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

static void	frac_initialize(t_mlx *mlx, int x, int y)
{
	mlx->id = mlx_init();
	mlx->win.max_x = x;
	mlx->win.max_y = y;
	if (!(mlx->map = ft_memalloc(x * y * sizeof(int))))
		frac_cleanup(3, mlx);
	if (!(mlx->win.id = mlx_new_window(mlx->id, x, y, mlx->frc.name)))
		frac_cleanup(2, mlx);
	if (!(mlx->img.id = mlx_new_image(mlx->id, x, y)))
		frac_cleanup(3, mlx);
	mlx->img.skt = mlx_get_data_addr(mlx->img.id,
			&mlx->img.bpp, &mlx->img.sl, &mlx->img.end);
	mlx->frc.res = 64;
	mlx->frc.zoom = 4;
	frac_identifier(mlx);
	frac_scale_c(mlx, &mlx->frc.cp, mlx->win.max_x / 2, mlx->win.max_y / 2);
	frac_printmap(mlx);
}

static void	fractol_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->win.id, fractol_kr_hook, (void*)mlx);
	mlx_mouse_hook(mlx->win.id, fractol_mhooks, (void*)mlx);
	mlx_hook(mlx->win.id, 6, 0, motion_hook, (void*)mlx);
	mlx_hook(mlx->win.id, 17, 0, exit_hook, (void*)mlx);
	mlx_loop(mlx->id);
}

int			main(int argc, char **argv)
{
	t_mlx	canvas;

	if (argc < 2)
		frac_cleanup(1, NULL);
	ft_bzero((void*)&canvas, sizeof(canvas));
	frac_color_palette(&canvas.palette);
	if (!(canvas.frc.name = ft_strdup(argv[1])))
		frac_cleanup(3, &canvas);
	frac_initialize(&canvas, MAX_X, MAX_Y);
	fractol_hooks(&canvas);
	return (0);
}
