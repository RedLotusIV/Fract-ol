/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:30:38 by amouhand          #+#    #+#             */
/*   Updated: 2024/07/09 20:55:46 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_controls(int flag)
{
	if (flag)
	{
		ft_printf("\n====== Fract-Ol Controls ====\n");
		ft_printf("\tZoom: Mouse wheel\n");
		ft_printf("\tMove: Arrows\n");
		ft_printf("\tChange iterations: + or -\n");
		ft_printf("\tChange fractal: Space\n");
		ft_printf("\tExit: ESC\n");
		ft_printf("==============================\n\n");
	}
	else
	{
		ft_printf("Usage: ./fractol [fractal] (Optional [X] [Y] for Julia) \n");
		ft_printf("Fractals: mandelbrot(or M, m), julia(or J, j)\n");
	}
	return (0);
}

int	trailing_spaces(char *str, int i, int flag)
{
	if (flag)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		else
			return (1);
	}
	return (0);
}
