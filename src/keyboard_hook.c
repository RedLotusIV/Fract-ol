/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:20:20 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/22 03:20:02 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_hook(int keycode, t_mlx *fractol)
{
	if (keycode == ESC)
		end_window(fractol);
	if (keycode == UP)
		fractol->y_offset -= (0.5 * -fractol->zoom);
	if (keycode == DOWN)
		fractol->y_offset += (0.5 * -fractol->zoom);
	if (keycode == LEFT)
		fractol->x_offset -= (0.5 * fractol->zoom);
	if (keycode == RIGHT)
		fractol->x_offset += (0.5 * fractol->zoom);
	if (keycode == PLUS || keycode == MINUS)
		increase_iter(keycode, fractol);
	if (keycode == SPACE)
		switch_fractal(fractol);
	if (keycode == ESC || keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT)
		render(fractol);
	return (0);
}

int	increase_iter(int keycode, t_mlx *fractol)
{
	if (keycode == PLUS && fractol->max_iter < 1000)
		fractol->max_iter += 10;
	if (keycode == MINUS && fractol->max_iter >= 20)
		fractol->max_iter -= 10;
	if (keycode == PLUS || keycode == MINUS)
		render(fractol);
	return (0);
}

void	switch_fractal(t_mlx *fractol)
{
	fractol->fractal = !fractol->fractal;
	fractol->x_offset = 0;
	fractol->y_offset = 0;
	fractol->zoom = 1.0;
	fractol->max_iter = 100;
	fractol->min.real = -2.0;
	fractol->min.imag = -2.0;
	fractol->max.real = 2.0;
	fractol->max.imag = 2.0;
	fractol->mouse_x = 0;
	fractol->mouse_y = 0;
	render(fractol);
}
