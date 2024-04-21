/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:20:32 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/21 03:38:56 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int keycode,int x,int y, t_mlx *fractol)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		fractol->zoom *= 1.1;
		render(fractol);
	}
	else if (keycode == 5)
	{
		fractol->zoom /= 1.1;
		render(fractol);
	}
	return (0);
}