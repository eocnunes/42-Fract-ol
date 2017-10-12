/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 23:00:52 by enunes            #+#    #+#             */
/*   Updated: 2017/10/12 04:30:12 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				clr_grade(int i, t_mlx *mlx)
{
	int		red;
	int		green;
	int		blue;
	double	co;

	if (i == mlx->i)
		return (0);
	co = mlx->freq * (i + 1);
	red = cos(co) * 127 + 128;
	green = cos(co + mlx->color) * 127 + 128;
	blue = cos(co + 2 * mlx->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}

void			put_pxl(t_fractol *f, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (f->bpp / 8) + y * (f->size_line);
	while (i < (f->bpp / 8))
	{
		f->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int				draw(t_mlx *mlx)
{
	int	x;
	int	y;
	int color;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			if (mlx->f->nb == 1)
				color = clr_grade(julia(mlx, x, y), mlx);
			else if (mlx->f->nb == 2)
				color = clr_grade(mandelbrot(mlx, x, y), mlx);
			else if (mlx->f->nb == 3)
				color = clr_grade(tricorn(mlx, x, y), mlx);
			else if (mlx->f->nb == 4)
				color = clr_grade(burningship(mlx, x, y), mlx);
			else if (mlx->f->nb == 5)
				color = clr_grade(dragon(mlx, x, y), mlx);
			put_pxl(mlx->f, x, y, color);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->f->img, 0, 0);
	return (0);
}
