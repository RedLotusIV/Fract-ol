/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:31:06 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/21 05:13:44 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef	struct	s_mlx
{
	void		*mlx;
	void 		*win;
	void 		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			fractal;
	double		rn;
	double		in;
	double		zoom;
	int			y;
	int			x;
	int			x_offset;
	int			y_offset;
}				t_mlx;

typedef struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

# define WIDTH 800
# define HEIGHT 800

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "controls.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
// mlx
int		end_window(t_mlx *fractol);
void	ft_mlxdisplay(t_mlx *fractol, int x, int y, int color);
void	render(t_mlx *fractol);
void	ft_exit_mlx(int status, t_mlx *fractol);
// parsing
int		parsing(char **av, char ac, t_mlx *fractol);
void	initialise(t_mlx *fractol);
void	clean_args(t_mlx *fractol);
int		print_controls(int flag);
// coordinates
int		coordinates_check(char **av, int ac ,t_mlx *fractol);
double	ft_atof(char *str);
int		space_check(char *str, int *sign);
// calculation
void	mandelbrot(t_mlx *fractol);
int		julia(t_mlx *fractol);
int		calculate_mandelbrot(t_mlx *fractol, int x, int y);
double	scale(double x, double new_min, double new_max, double old_max);
// hooks
int		keyboard_hook(int keycode, t_mlx *fractol);
int		mouse_hook(int keycode, int x, int y, t_mlx *fractol);
// math
t_complex	add(t_complex a, t_complex b);
t_complex	square(t_complex a);

#endif