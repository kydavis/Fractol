/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:21:30 by kdavis            #+#    #+#             */
/*   Updated: 2017/06/22 13:48:00 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/*
** Creates .fdf snapshot of the current fractal for use with the fdf program.
** Will overwrite the previous snapshot if it exists.
*/

static int	create_map(t_mlx *mlx, t_vec *out)
{
	char	*chunk;
	int		len;
	int		i;
	int		total;

	i = ~0;
	total = mlx->win.max_y * mlx->win.max_x;
	while (++i < total)
	{
		if (!((i + 1) % mlx->win.max_x))
			len = ft_asprintf(&chunk, "%d,%#x\n", mlx->map[i],
						mlx->palette.large[mlx->map[i]]);
		else
			len = ft_asprintf(&chunk, "%d,%#x ", mlx->map[i],
						mlx->palette.large[mlx->map[i]]);
		if (len == -1)
			return (-1);
		if (!(ft_vecapp(out, chunk, len)))
		{
			free(chunk);
			return (-1);
		}
		free(chunk);
	}
	return (1);
}

void fractol_to_file(t_mlx *mlx)
{
	t_vec	output;
	int		fd;
	int		ern;
	char	*file;

	if ((ft_asprintf(&file, "%s.fdf", mlx->frc.name)) == -1)
		frac_cleanup(3, mlx);
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	ft_strdel(&file);
	if (fd < 0)
		frac_cleanup(4, mlx);
	if (!(ft_initialize_vec(&output, sizeof(char), 1000, 0)))
		frac_cleanup(3, mlx);
	ern = create_map(mlx, &output);
	if (ern == 1)
		ern = write(fd, output.arr, output.len); 
	free(output.arr);
	if (close(fd) < 0 || ern == -1)
		frac_cleanup(4, mlx);
}
