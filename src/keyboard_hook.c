/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:20:20 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/21 05:50:25 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_hook(int keycode, t_mlx *fractol)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC)
		end_window(fractol);
	if (keycode == UP)
		fractol->y_offset -= 0.1;
	if (keycode == DOWN)
		fractol->y_offset += 0.1;
	if (keycode == LEFT)
		fractol->x_offset -= 0.1;
	if (keycode == RIGHT)
		fractol->x_offset += 0.1;
	// if (keycode == ESC || keycode == UP || keycode == DOWN 
	// 	|| keycode == LEFT || keycode == RIGHT)
	render(fractol);
	return (0);
}