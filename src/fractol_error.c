/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:18:24 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/18 17:50:01 by kdavis           ###   ########.fr       */
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
		ft_printf("List of valid fractols:\n%s\n%s\n%s\n%s\n%s\n%s",
				FRACTOL1, FRACTOL2, FRACTOL3, FRACTOL4, FRACTOL5, FRACTOL6);
	}
	else if (en == 2)
		ft_printf("Failed to create window\n");
	else if (en == 3)
		ft_printf("Could not allocate enough space\n");
}

void	frac_cleanup(int en, t_mlx *c)
{
	if (c)
	{
		if (c->img.id && c->mlx)
			mlx_destroy_image(c->mlx, c->img.id);
		if (c->win.id && c->mlx)
			mlx_destroy_window(c->mlx, c->win.id);
		ft_memdel((void*)&c->frc.name);
	}
	frac_perror(en);
	exit(en);
}
