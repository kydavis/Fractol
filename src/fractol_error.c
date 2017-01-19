/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:18:24 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/19 11:23:18 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

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
		ft_printf("Failed to create window\n");
	else if (en == 3)
		ft_printf("Could not allocate enough space\n");
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
	}
	frac_perror(en);
	exit(en);
}
