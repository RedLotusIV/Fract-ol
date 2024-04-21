/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 02:28:13 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/21 05:45:13 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mlxdisplay(t_mlx *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->size_line + x * (fractol->bpp / 8));
	*(unsigned int*)dst = color;
}

void	render(t_mlx *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bpp, \
					&fractol->size_line, &fractol->endian);
	mlx_clear_window(fractol->mlx, fractol->win);
	if (fractol->fractal)
		mandelbrot(fractol);
	else
		julia(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	initialise(t_mlx *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bpp, \
					&fractol->size_line, &fractol->endian);
}
double scale(double x, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (x) / (old_max) + new_min);
}