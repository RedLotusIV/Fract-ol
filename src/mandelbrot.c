/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:54:06 by amouhand          #+#    #+#             */
/*   Updated: 2024/07/09 18:13:49 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_mandelbrot(t_mlx *fractol, int x, int y)
{
	int			iter;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z.real = (scale(x, -2, 2, WIDTH) * fractol->zoom) + (fractol->x_offset);
	z.imag = (scale(y, 2, -2, HEIGHT) * fractol->zoom) + (fractol->y_offset);
	c.imag = z.imag;
	c.real = z.real;
	while (iter < fractol->max_iter)
	{
		z = add(square(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (ft_mlxdisplay(fractol, x, y, color(fractol, iter)), 0);
		iter++;
	}
	return (1);
}

void	mandelbrot(t_mlx *fractol)
{
	fractol->y = 0;
	fractol->x = 0;
	while (fractol->y < HEIGHT)
	{
		fractol->x = 0;
		while (fractol->x < WIDTH)
		{
			calculate_mandelbrot(fractol, fractol->x, fractol->y);
			fractol->x++;
		}
		fractol->y++;
	}
}
