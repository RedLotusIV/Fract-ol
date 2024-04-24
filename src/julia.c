/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:54:09 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/23 01:45:52 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculate_julia(t_mlx *fractol, int y, int x)
{
	int			iter;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z.real = (scale(x, -2, 2, WIDTH) * fractol->zoom) + (fractol->x_offset);
	z.imag = (scale(y, 2, -2, HEIGHT) * fractol->zoom) + (fractol->y_offset);
	c.imag = fractol->in;
	c.real = fractol->rn;
	while (iter < fractol->max_iter)
	{
		z = add(square(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (ft_mlxdisplay(fractol, x, y, color(fractol, iter)), 0);
		iter++;
	}
	return (1);
}

void	julia(t_mlx *fractol)
{
	fractol->y = 0;
	fractol->x = 0;
	while (fractol->y < HEIGHT)
	{
		fractol->x = 0;
		while (fractol->x < WIDTH)
		{
			calculate_julia(fractol, fractol->y, fractol->x);
			fractol->x++;
		}
		fractol->y++;
	}
}
