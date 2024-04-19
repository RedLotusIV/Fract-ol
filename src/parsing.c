/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:55:21 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/18 23:36:18 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int parsing(char **av, char ac, t_mlx *fractol)
{
	if (ac > 3 || ac < 1)
	{
		print_controls(0);
		ft_exit_mlx(1, fractol);
	}
	if (ac >= 1)
	{
		if (!(ft_strncmp(av[0], "J", 1)) \
			|| !(ft_strncmp(av[0], "j", 1)))
			fractol->fractal = 0;
		else if ( !(ft_strncmp(av[0], "M", 1)) \
			|| !(ft_strncmp(av[0], "m", 1)))
			fractol->fractal = 1;
		else
		{
			print_controls(0);
			ft_exit_mlx(1, fractol);
		}
		if (ac >= 2 || ac <= 3)
			coordinates_check(av + 1, ac - 1, fractol);
	}
	return (0);
}
int	coordinates_check(char **av, int ac ,t_mlx *fractol)
{
	int i;

	i = 0;
	if ((!ft_strchr(av[0], ',') && !ft_strchr(av[0], '.')) \
	|| (!ft_strchr(av[1], ',') && !ft_strchr(av[1], '.')))
	{
		print_controls(0);
		ft_exit_mlx(1, fractol);
	}
	fractol->rn = ft_atof(av[0]);
	fractol->in = ft_atof(av[1]);
	return (0);
}
double ft_atof(char *str)
{
	int i;
	double number;
	double divider;
	int sign;

	number = 0.0;
	sign = 1;
	divider = 0.1;
	i = space_check(str, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] && (str[i] == '.' || str[i] == ','))
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number + ((str[i] - '0') * divider);
		divider *= 0.1;
		i++;
	}
	return (number * sign);
}
int space_check(char *str, int *sign)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}