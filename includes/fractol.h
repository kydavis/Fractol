/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:30:23 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/14 10:48:22 by kdavis           ###   ########.fr       */
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
# define ZOOMOT 4
# define ZOOMIN 5
# define RWHEEL 6
# define LWHEEL 7

/*
** Program related macros
*/
# define MAX_X		720
# define MAX_Y		1080
# define FRACTOL1	"Julia"
# define FRACTOL2	"Mandelbrot"
# define FRACTOL3	"BurningSet"
# define FRACTOL4	"Burning"
# define FRACTOL5	"LilySet"
# define FRACTOL6	"Lily"
# define FRACTOL7	"WeirdSet"
# define FRACTOL8	"Weird"

typedef	struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

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
	t_complex	ctr;
}				t_img;

typedef	struct	s_window
{
	void		*id;
	int			max_y;
	int			max_x;
}				t_win;

typedef struct	s_palette
{
	int			large[257];
	int			p[8][64];
	int			trippy[9];
}				t_palette;

typedef struct	s_fractal
{
	char		*name;
	double		zoom;
	t_complex	cp;
	int			id;
	int			res;
	char		trip;
	char		lock;
}				t_fractal;

typedef	struct	s_mlx
{
	void		*id;
	t_win		win;
	t_img		img;
	t_palette	palette;
	t_fractal	frc;
}				t_mlx;

/*
** fractol_color_palette.c
*/
void			frac_lpalette_loader(t_palette *pal, int start, int size);
int				frac_color_palette(t_palette *pal);

/*
** fractol_pixel.c
*/
int				pixel_to_img(t_mlx *mlx, t_pix *p);

/*
** fractol_index.c
*/
void			frac_scale_c(t_mlx *mlx, t_complex *c, int x, int y);
void			frac_printmap(t_mlx *mlx);

/*
** fractol_zoom.c
*/
void			fractol_zoom(int button, t_mlx *c, int x, int y);

/*
** fractol_hooks.c
*/
int				exit_hook(void *param);
int				fractol_kr_hook(int kc, void *param);
int				fractol_mhooks(int button, int x, int y, void *param);
int				motion_hook(int x, int y, void *param);

/*
** fractol_error.c
*/
void			frac_cleanup(int en, t_mlx *c);

/*
** Fractol functions
*/
int				julia(t_mlx *mlx, t_complex *z, t_complex *c, t_complex *zs);
int				burning(t_mlx *mlx, t_complex *z, t_complex *c, t_complex *zs);
int				lily(t_mlx *mlx, t_complex *z, t_complex *c, t_complex *zs);
int				weird(t_mlx *mlx, t_complex *z, t_complex *c, t_complex *zs);
#endif
