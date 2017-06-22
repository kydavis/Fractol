/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:18:24 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/22 12:12:44 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	frac_perror(int en)
{
	if (en == 1)
	{
		ft_printf("Usage: ./fractol [valid fractol]\n");
		ft_printf("List of valid fractols:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
				FRACTOL1, FRACTOL2, FRACTOL3, FRACTOL4, FRACTOL5, FRACTOL6,
				FRACTOL7, FRACTOL8);
	}
	else if (en == 2)
		ft_dprintf(2, "Failed to create window\n");
	else if (en == 3)
		ft_dprintf(2, "Could not allocate enough space\n");
	else if (en == 4)
		ft_dprintf(2, "Error creating fdf map file\n");
}

void	frac_cleanup(int en, t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->img.id && mlx->id)
			mlx_destroy_image(mlx->id, mlx->img.id);
		if (mlx->win.id && mlx->id)
			mlx_destroy_window(mlx->id, mlx->win.id);
		ft_memdel((void*)&mlx->frc.name);
		ft_memdel((void*)&mlx->map);
	}
	frac_perror(en);
	exit(en);
}
