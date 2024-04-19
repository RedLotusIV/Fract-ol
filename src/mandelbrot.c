/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:54:06 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/19 03:41:09 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_mandelbrot(t_mlx *fractol, int x, int y)
{
	int iter;
	t_complex z;
	t_complex c;
	
	iter = 0;
	z.real = scale(x, -2, 2, WIDTH);
	z.imag = scale(y, 2, -2, HEIGHT);
	c.imag = z.imag;
	c.real = z.real;
	while (iter < MAX_ITER)
	{
		z = add(square(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (ft_mlxdisplay(fractol, x, y, scale(iter, 0, 0xFFFFFF,
				MAX_ITER)), 0);
		// add the max iteration to the struct
		// when you press + or - you will increase or decrease the max iteration
		// so it changes the color of the fractal
		iter++;
	}
	return (1);
}

void	mandelbrot(t_mlx *fractol)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_mandelbrot(fractol, x, y);
			x++;
		}
		y++;
	}
}