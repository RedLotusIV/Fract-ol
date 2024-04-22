/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:50:13 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/22 03:17:29 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	color(t_mlx *fractol, int iter)
{
	int	r;
	int	g;
	int	b;
	int	var;

	if (iter == fractol->max_iter)
		return (BLACK);
	var = scale(iter, 0, 255, fractol->max_iter);
	r = (var << 5) & 0xff;
	g = (var << 3) & 0xff;
	b = (var << 1) & 0xff;
	return ((r << 16) | (g << 8) | b);
}
