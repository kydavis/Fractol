/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_palette.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:56:09 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/17 11:38:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

static void	frac_itocolor(t_color *color, int icolor)
{
	color->red = (icolor & 0xFF0000);
	color->green = (icolor & 0x00FF00);
	color->blue = (icolor & 0x0000FF);
}

static void	frac_extra_steps(t_color *middle, t_color *extra)
{
	t_color sign;

	sign.red = (extra->red > 0 ? 1 : -1);
	sign.green = (extra->green > 0 ? 1 : -1);
	sign.blue = (extra->blue > 0 ? 1 : -1);
	if (extra->red)
	{
		middle->red += sign.red * 0x010000;
		extra->red -= sign.red;
	}
	if (extra->green)
	{
		middle->green += sign.green * 0x000100;
		extra->green -= sign.green;
	}
	if (extra->blue)
	{
		middle->blue += sign.blue * 0x000001;
		extra->blue -= sign.blue;
	}
}

/*
** frac_palette_maker creates a color palette that ranges from scolor to ecolor
** It is important to note that we want the color gradient to be inclusive for
** both the start and end colors. For this reason when dividing up the steps
** and extras we calculate using i = size - 1;
** range[0] = t_color struct for starting color.
** range[1] = t_color struct for ending color.
*/

void		frac_palette_maker(int *palette, int size,
			int scolor, int ecolor)
{
	t_color range[3];
	t_color step;
	t_color	extra;
	int	i;

	i = size - 1;
	frac_itocolor(&range[0], scolor);
	frac_itocolor(&range[1], ecolor);
	step.red = (range[1].red - range[0].red) / (i * 0x010000);
	step.green = (range[1].green - range[0].green) / (i * 0x000100);
	step.blue = (range[1].blue - range[0].blue) / i;
	extra.red = ((range[1].red - range[0].red) % (i * 0x010000)) / 0x010000;
	extra.green = ((range[1].green - range[0].green) % (i * 0x100)) / 0x100;
	extra.blue = (range[1].blue - range[0].blue) % i;
/*	ft_printf("Steps r:%#x g:%#x b:%d\nExtra r:%#x g:%#x b:%d\n",
			step.red, step.green, step.blue,
			extra.red, extra.green, extra.blue);*/
	i = ~0;
	while (++i < size)
	{
		palette[i] = range[0].red | range[0].green | range[0].blue;
		range[0].red += step.red * 0x010000;
		range[0].green += step.green * 0x000100;
		range[0].blue += step.blue;
		frac_extra_steps(&range[0], &extra);
	}
}

/*
** frac_lpalette_loader loads the large palette fractol from the various
** available color palettes. It takes the starting palette, and the number
** of color palettes to be combined into the large palette.
*/

void	frac_lpalette_loader(t_palette *pal, int start, int size)
{
	int	duplicates;
	int	offset;
	int	i;
	int	j;
	int	k;

	duplicates = 256 / (size * 64); 
	i = start - 1;
	size += start;
	offset = 0;
	while (++i < size)
	{
		j = ~0;
		while (++j < 64)
		{
			k = ~0;
			while (++k < duplicates)
			{
				pal->large[offset++] = pal->p[i][j];
/*			ft_printf("pal->large:%#08x index:%d\n",
					pal->large[offset - 1], offset);*/
			}
		}
	}
}

/*
** frac_color_palette is used to initialize the color gradient for fractol
*/

int	frac_color_palette(t_palette *pal)
{
	frac_palette_maker(pal->p[0], 64, 0x0000FF, 0xFF0000);
	frac_palette_maker(pal->p[1], 64, 0xFF0000, 0xFFFF00);
	frac_palette_maker(pal->p[2], 64, 0xFFFF00, 0x00FF00);
	frac_palette_maker(pal->p[3], 64, 0x00FF00, 0x00FFFF);
	frac_palette_maker(pal->p[4], 64, 0x00FF80, 0x800080);
	frac_palette_maker(pal->p[5], 64, 0x800080, 0xFF8000);
	frac_palette_maker(pal->p[6], 64, 0xFF8000, 0xFF00FF);
	frac_palette_maker(pal->p[7], 64, 0xFF00FF, 0x000000);
	frac_lpalette_loader(pal, 0, 4);
	return (0);
}
