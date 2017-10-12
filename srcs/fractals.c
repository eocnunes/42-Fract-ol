/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 23:51:00 by enunes            #+#    #+#             */
/*   Updated: 2017/10/11 20:18:21 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_mlx *mlx, int x, int y)
{
	t_fractol		*f;
	int				i;
	double			tmp;

	f = mlx->f;
	i = -1;
	f->pr = mlx->min_x + ((double)x * (mlx->max_x - mlx->min_x) / WIN_W);
	f->pi = mlx->min_y + ((double)y * (mlx->max_y - mlx->min_y) / WIN_H);
	while (++i < mlx->i && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
	}
	return (i);
}

int	mandelbrot(t_mlx *mlx, int x, int y)
{
	t_fractol		*f;
	int				i;
	double			tmp;

	f = mlx->f;
	i = -1;
	f->pr = 0.0;
	f->pi = 0.0;
	f->cr = mlx->min_x + ((double)x * (mlx->max_x - mlx->min_x) / WIN_W);
	f->ci = mlx->min_y + ((double)y * (mlx->max_y - mlx->min_y) / WIN_H);
	while (++i < mlx->i && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
	}
	return (i);
}

int	tricorn(t_mlx *mlx, int x, int y)
{
	t_fractol		*f;
	int				i;
	double			tmp;

	f = mlx->f;
	i = -1;
	f->pr = 0.0;
	f->pi = 0.0;
	f->cr = mlx->min_x + ((double)x * (mlx->max_x - mlx->min_x) / WIN_W);
	f->ci = mlx->min_y + ((double)y * (mlx->max_y - mlx->min_y) / WIN_H);
	while (++i < mlx->i && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = -2 * f->pi * tmp + f->ci;
	}
	return (i);
}

int	burningship(t_mlx *mlx, int x, int y)
{
	t_fractol		*f;
	int				i;
	double			tmp;

	f = mlx->f;
	i = -1;
	f->pr = 0.0;
	f->pi = 0.0;
	f->cr = mlx->min_x + ((double)x * (mlx->max_x - mlx->min_x) / WIN_W);
	f->ci = mlx->min_y + ((double)y * (mlx->max_y - mlx->min_y) / WIN_H);
	while (++i < mlx->i && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * fabs(f->pi * tmp) + f->ci;
	}
	return (i);
}

int	dragon(t_mlx *mlx, int x, int y)
{
	t_fractol		*f;
	int				i;
	double			tmp;

	f = mlx->f;
	i = -1;
	f->pr = 0.0;
	f->pi = 0.0;
	f->cr = mlx->min_x + ((double)x * (mlx->max_x - mlx->min_x) / WIN_W);
	f->ci = mlx->min_y + ((double)y * (mlx->max_y - mlx->min_y) / WIN_H);
	while (++i < mlx->i && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		i++;
		tmp = f->pr;
		f->pr = f->pr * f->pr * f->pr - (3 * f->pr * f->pi * f->pi) - f->cr;
		f->pi = (3 * tmp * tmp * f->pi) + f->ci;
	}
	return (i);
}
