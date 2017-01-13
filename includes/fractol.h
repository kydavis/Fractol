/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:30:23 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/13 14:23:10 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef	struct	s_fractol
{
	char		*name;
}				t_frac;

typedef	struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pix;

typedef struct	s_image
{
	void		*id;
	char		*skt;
	int			bpp;
	int			sl;
	int			end;
}				t_img;

typedef	struct	s_window
{
	void		*id;
	int			max_y;
	int			max_x;
}				t_win;

typedef	struct	s_mlx
{
	void		*mlx;
	int			*c_palette;
	t_win		win;
	t_img		img;
}				t_mlx;

#endif
