/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:30:23 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/15 16:22:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Keycode related macros
*/
# define ESC  53
# define Q  12
# define E  14
# define W  13
# define S  1
# define D  2
# define A  0
# define LA 123
# define RA 124
# define UA 126
# define DA 125
# define PS	69
# define MS 78
# define N1 83
# define N2 84
# define N3 85
# define N6 88
# define N4 86
# define N5 87
# define N7 89
# define N9 92
# define N8 91
# define N0 82
# define SPACE 49
# define RSHIFT 258
# define LSHIFT 257
# define LCLICK 1
# define RCLICK 2
# define MCLICK 3
# define DWHEEL 4
# define UWHEEL 5
# define RWHEEL 6
# define LWHEEL 7

/*
** Program related macros
*/
# define MAX_X		1080
# define MAX_Y		720
# define FRACTOL1	"Julia"
# define FRACTOL2	"Mandelbrot"
# define FRACTOL3	"Test"

typedef	struct	s_bounds
{
	int			max_r;
	int			min_r;
	int			max_i;
	int			min_i;
}				t_bounds;

typedef	struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

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

typedef struct	s_palette
{
	int			large[513];
	int			p[8][64];
}				t_palette;

typedef	struct	s_mlx
{
	void		*mlx;
	char		*name;
	t_win		win;
	t_img		img;
	t_palette	palette;
}				t_mlx;

/*
** fractol_color_palette.c
*/
int		frac_color_palette(t_palette *pal);

/*
** fractol_index.c
*/
void	frac_dispatcher(char *name, t_mlx *c);

/*
** fractol_error.c
*/
void	frac_cleanup(int en, t_mlx *c);
#endif
