/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 23:17:41 by enunes            #+#    #+#             */
/*   Updated: 2017/10/12 04:31:00 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			controls(void)
{
	ft_putendl("\n\e[1;97m-------------- Fract'ol Controls --------------");
	ft_putendl("\n\t\e[1;93mLeft Btn(mouse):\e[97m Zoom in");
	ft_putendl("\t\e[1;93mRight Btn(mouse):\e[97m Zoom out");
	ft_putendl("\t\e[1;93mSpace:\e[97m Switch fractals");
	ft_putendl("\t\e[1;93mTAB (Julia):\e[97m Enable mouse motion");
	ft_putendl("\t\e[1;93mWASD:\e[97m Movement");
	ft_putendl("\t\e[1;93mE:\e[97m Increase iterations");
	ft_putendl("\t\e[1;93mQ:\e[97m Decrease iterations");
	ft_putendl("\t\e[1;93mC:\e[97m Change colorgrade");
	ft_putendl("\t\e[1;93mX:\e[97m Increase frequency");
	ft_putendl("\t\e[1;93mZ:\e[97m Decrease frequency");
	ft_putendl("\t\e[1;93mESC:\e[97m Exit\n");
	ft_putendl("\e[1;97m ----------------------------------------------");
	return (0);
}

void		reset(t_mlx *mlx)
{
	mlx->f->cr = -1.1380;
	mlx->f->ci = 0.2403;
	mlx->f->pr = 0.0;
	mlx->f->pi = 0.0;
	mlx->f->mx = 0.0;
	mlx->f->my = 0.0;
	mlx->min_x = -3.2;
	mlx->min_y = -3.2;
	mlx->max_x = 3.4;
	mlx->max_y = 3.4;
	mlx->freq = 0.1;
	mlx->i = 16.0;
	mlx->color = 2;
}

int			move(int keycode, t_mlx *mlx)
{
	double	c;

	c = ((mlx->max_x - mlx->min_x) / WIN_W) * 50;
	if (keycode == 0)
	{
		mlx->min_x += c;
		mlx->max_x += c;
	}
	else if (keycode == 2)
	{
		mlx->min_x -= c;
		mlx->max_x -= c;
	}
	else if (keycode == 1)
	{
		mlx->min_y -= c;
		mlx->max_y -= c;
	}
	else if (keycode == 13)
	{
		mlx->min_y += c;
		mlx->max_y += c;
	}
	return (0);
}

int			set_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 49)
	{
		reset(mlx);
		if (mlx->f->nb < 5)
			mlx->f->nb++;
		else
			mlx->f->nb = 1;
	}
	if (keycode == 48)
		mlx_hook(mlx->win, 6, (1L << 6), motion, mlx);
	return (0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 14)
		mlx->i = (mlx->i < 8000) ? mlx->i * 2 : mlx->i;
	else if (keycode == 12)
		mlx->i = (mlx->i > 2) ? mlx->i / 2 : mlx->i;
	else if (keycode == 8)
		mlx->color++;
	else if (keycode == 7)
		mlx->freq = (mlx->freq < 200) ? mlx->freq * 2 : mlx->freq;
	else if (keycode == 6)
		mlx->freq = (mlx->freq > 0.1) ? mlx->freq / 2 : mlx->freq;
	set_hook(keycode, mlx);
	move(keycode, mlx);
	draw(mlx);
	return (0);
}
