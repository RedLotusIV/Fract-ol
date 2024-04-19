/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:22:38 by amouhand          #+#    #+#             */
/*   Updated: 2024/04/19 03:23:10 by amouhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex res;

	res.real = a.real + b.real;
	res.imag = a.imag + b.imag;
	return (res);
}

t_complex	square(t_complex a)
{
	t_complex res;

	res.real = a.real * a.real - a.imag * a.imag;
	res.imag = 2 * a.real * a.imag;
	return (res);
}