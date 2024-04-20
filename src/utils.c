/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:00:57 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/20 22:51:25 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
void	ft_exit_mlx(int status, t_mlx *fractol)
{
	if (!fractol)
		exit(status);
	if (fractol->img && fractol->mlx)
		mlx_destroy_image(fractol->mlx, fractol->img);
	if (fractol->win && fractol->mlx)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_loop_end(fractol->mlx);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	if (fractol)
	{
		free(fractol);
		fractol = NULL;
	}
	exit(status);
}
int	end_window(t_mlx *fractol)
{
	ft_exit_mlx(0, fractol);
	return (0);
}
void	clean_args(t_mlx *fractol)
{
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->img = NULL;
	fractol->addr = NULL;
	fractol->bpp = 0;
	fractol->size_line = 0;
	fractol->endian = 0;
	fractol->fractal = -1;
	fractol->rn = 0;
	fractol->in = 0;
	fractol->zoom = 1.0;
}
