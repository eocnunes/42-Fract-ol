/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 21:22:24 by enunes            #+#    #+#             */
/*   Updated: 2017/10/12 18:18:32 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WIN_W 800
# define WIN_H 800

typedef struct	s_fractol
{
	void		*img;
	double		pr;
	double		pi;
	double		cr;
	double		ci;
	double		mx;
	double		my;
	int			bpp;
	int			endian;
	int			size_line;
	char		*d;
	int			nb;
}				t_fractol;

typedef struct	s_mlx
{
	t_fractol	*f;
	void		*mlx;
	void		*win;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		i;
	double		freq;
	int			color;
}				t_mlx;

/*
** ---------------------- fractol.c -----------------------
*/
t_mlx			*mlx_set(char *s);
t_fractol		*frac_set(char *s);

/*
** ----------------------- draw.c -------------------------
*/
int				draw(t_mlx *mlx);
void			put_pxl(t_fractol *f, int x, int y, int color);
int				clr_grade(int i, t_mlx *mlx);

/*
** --------------------- fractals.c -----------------------
*/
int				julia(t_mlx *mlx, int x, int y);
int				mandelbrot(t_mlx *mlx, int x, int y);
int				tricorn(t_mlx *mlx, int x, int y);
int				burningship(t_mlx *mlx, int x, int y);
int				dragon(t_mlx *mlx, int x, int y);

/*
** ----------------------- keys.c -------------------------
*/
int				key_hook(int keycode, t_mlx *mlx);
int				set_hook(int keycode, t_mlx *mlx);
int				move(int keycode, t_mlx *mlx);
void			reset(t_mlx *mlx);
int				controls(void);

/*
** ----------------------- mouse.c ------------------------
*/
int				motion(int x, int y, t_mlx *mlx);
int				mouse(int btn, int x, int y, t_mlx *mlx);

#endif
