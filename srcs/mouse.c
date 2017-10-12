/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 23:27:18 by enunes            #+#    #+#             */
/*   Updated: 2017/10/11 06:44:08 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse(int btn, int x, int y, t_mlx *mlx)
{
	double	dx;
	double	dy;

	dx = mlx->max_x - mlx->min_x;
	dy = mlx->max_y - mlx->min_y;
	mlx->f->mx = ((double)(x) / WIN_W * dx) - dx / 2 + mlx->f->mx;
	mlx->f->my = (double)(y) / WIN_H * dy - dy / 2 + mlx->f->my;
	if ((btn == 1 || btn == 5) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		mlx->min_x = mlx->f->mx - (dx / 1.5) / 2;
		mlx->max_x = mlx->f->mx + (dx / 1.5) / 2;
		mlx->min_y = mlx->f->my - (dy / 1.5) / 2;
		mlx->max_y = mlx->f->my + (dy / 1.5) / 2;
	}
	else if ((btn == 2 || btn == 4) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		mlx->min_x = mlx->f->mx - (dx * 1.5) / 2;
		mlx->max_x = mlx->f->mx + (dx * 1.5) / 2;
		mlx->min_y = mlx->f->my - (dy * 1.5) / 2;
		mlx->max_y = mlx->f->my + (dy * 1.5) / 2;
	}
	return (draw(mlx));
}

int			motion(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && mlx->f->nb == 1)
	{
		mlx->f->cr = mlx->min_x + ((x * mlx->max_x) / WIN_W);
		mlx->f->ci = mlx->min_y + ((y * mlx->max_y) / WIN_H);
	}
	return (draw(mlx));
}
