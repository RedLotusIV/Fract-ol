/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:40:02 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/18 22:00:20 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int ac, char *av[])
{
	t_mlx	*fractol;
	int flag = 0;
	(void)av;
	fractol = (t_mlx *)malloc(sizeof(t_mlx));
	if (!fractol)
		exit (1);
	print_controls(1);
	clean_args(fractol);
	parsing(av + 1, ac - 1, fractol);
	initialise(fractol);
	render(fractol);
	mlx_hook(fractol->win, CLOSE_WINDOW, 0, &end_window, fractol);
	mlx_key_hook(fractol->win, &keyboard_hook, fractol);
	mlx_loop(fractol->mlx);
}
