/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:10:25 by ibaran            #+#    #+#             */
/*   Updated: 2019/03/15 18:39:35 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		f_error(t_fractol *fractol)
{
	fractol = 0;
	ft_printf("error occured\n");
	ft_printf("note: ussage: fractol <type>\n");
	ft_printf("available types:\n");
	ft_printf("  - Julia\n");
	ft_printf("  - Mandelbrot\n");
	ft_printf("  - BurningShip\n");
	return (1);
}

size_t		f_initialize(t_fractol *fractol, char *input)
{
	if (!(fractol->matrix = f_allocate_points(IMAGE_X, IMAGE_Y)))
		return (1);
	fractol->name = input;
/*	MIN_X = -2.5;
	MAX_X = 1.0;
	MIN_Y = -1.0;
	MAX_Y = 1.0;*/
	MIN_X = -2.0;
	MAX_X = 2.0;
	MIN_Y = -2.0;
	MAX_Y = 2.0;
	STEP_X = (MAX_X - MIN_X) / (float)IMAGE_X;
	STEP_Y = (MAX_Y - MIN_Y) / (float)IMAGE_Y;
	CR = GOLD - 2;
	CI = GOLD - 1;
	MOUSE_CUR_X = 0;
	MOUSE_CUR_Y = 0;
	MOUSE_PRE_X = 0;
	MOUSE_PRE_Y = 0;
	ITER_RANGE = 15;
	return (0);
}

size_t		f_check(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ft_strcmp(av[1], "Julia") != 0 &&
			ft_strcmp(av[1], "Mandelbrot") != 0 &&
			ft_strcmp(av[1], "BurningShip") != 0)
		return (1);
	return (0);
}
