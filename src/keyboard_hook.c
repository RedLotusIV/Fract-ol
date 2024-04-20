/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:20:20 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/20 22:15:28 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_hook(int keycode, t_mlx *fractol)
{
	printf("keyboard code\t: %d\n", keycode);
	if (keycode == ESC)
		end_window(fractol);
	// if (keycode == UP)
	// 	fractol->y -= 0.1;
	// if (keycode == DOWN)
	// 	fractol->y += 0.1;
	// if (keycode == LEFT)
	// 	fractol->x -= 0.1;
	// if (keycode == RIGHT)
	// 	fractol->x += 0.1;
	// render(fractol);
	return (0);
}