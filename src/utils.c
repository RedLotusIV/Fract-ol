/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:00:57 by amouhand          #+#    #+#             */
/*   Updated: 2024/07/09 21:00:34 by amouhand         ###   ########.fr       */
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
	fractol->in = 0.8;
	fractol->zoom = 1.0;
	fractol->x_offset = 0;
	fractol->y_offset = 0;
	fractol->max_iter = 100;
	fractol->min.real = -2.0;
	fractol->min.imag = -2.0;
	fractol->max.real = 2.0;
	fractol->max.imag = 2.0;
}

int	float_check(char *str)
{
	int	dot;
	int	spaceflag;
	int	i;

	i = space_check(str);
	if (str[i] == '-')
		i++;
	check_init(&dot, &spaceflag);
	while (str[i])
	{
		if (trailing_spaces(str, i, spaceflag))
			return (1);
		else
		{
			if (str[i] == '.')
				dot++;
			else if (!ft_isdigit(str[i]) && (str[i] == ' '
					|| str[i] == '\t' || str[i] == '\n'))
				spaceflag = 1;
			else if (!ft_isdigit(str[i]))
				return (0);
		}
		i++;
	}
	return (dot <= 1);
}

void	check_init(int *i, int *j)
{
	*i = 0;
	*j = 0;
}
