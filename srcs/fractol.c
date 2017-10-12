/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:10:08 by enunes            #+#    #+#             */
/*   Updated: 2017/10/12 04:50:00 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			usage_message(void)
{
	ft_putstr("\n\e[1;91mError!\e[90m\t");
	ft_putendl("\e[1;97mUsage: ./fractol fractal_number");
	ft_putendl("\n\e[1;93m------ Fractal List ------");
	ft_putendl("  1 - Julia ");
	ft_putendl("  2 - Mandelbrot");
	ft_putendl("  3 - Tricorn");
	ft_putendl("  4 - Burning Ship");
	ft_putendl("  5 - Dragon");
	ft_putendl("--------------------------");
}

t_fractol		*frac_set(char *s)
{
	t_fractol	*f;

	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	f->cr = -1.1380;
	f->ci = 0.2403;
	f->pr = 0.0;
	f->pi = 0.0;
	f->mx = 0.0;
	f->my = 0.0;
	f->nb = ft_atoi(s);
	return (f);
}

t_mlx			*mlx_set(char *s)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->f = frac_set(s)))
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->f->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "42-Fract'ol");
	mlx->f->d = mlx_get_data_addr(mlx->f->img, &mlx->f->bpp, &mlx->f->size_line\
				, &mlx->f->endian);
	mlx->min_x = -3.2;
	mlx->min_y = -3.2;
	mlx->max_x = 3.4;
	mlx->max_y = 3.4;
	mlx->freq = 0.1;
	mlx->i = 16.0;
	mlx->color = 2;
	return (mlx);
}

int				main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2 || ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 5)
	{
		usage_message();
		return (0);
	}
	if ((mlx = mlx_set(av[1])) != NULL)
	{
		controls();
		draw(mlx);
		mlx_key_hook(mlx->win, key_hook, mlx);
		mlx_mouse_hook(mlx->win, mouse, mlx);
		mlx_loop(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	return (0);
}
